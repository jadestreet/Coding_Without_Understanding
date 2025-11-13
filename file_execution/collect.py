import os
import pandas as pd
import subprocess
import re
import threading
from concurrent.futures import ThreadPoolExecutor, as_completed
import time
import signal
import sys
import psutil 
import ctypes
import gc
import argparse
rdtsc_lib = ctypes.CDLL('./librdtsc.so')
rdtsc_lib.rdtsc.restype = ctypes.c_uint64
from pathlib import Path
CURDIR = os.getcwd()

def build_parser():
    parser = argparse.ArgumentParser(description="Compile, run, and profile C code rows from a CSV.")
    parser.add_argument("--version", type=str, default="1.0", help="Run version tag (default: 1.0)")
    parser.add_argument("--rs", type=str, default=None, help="Run suffix (default: colv{version})")
    parser.add_argument("--rdtsc_lib", type=str, default=os.path.join(CURDIR, "librdtsc.so"),
                        help="Path to librdtsc.so (default: ./librdtsc.so)")
    parser.add_argument("--code_path", type=str, default=os.path.join(CURDIR, "c_main_indep_with_code.csv"),
                        help="Input CSV with code rows (default: c_main_indep_with_code.csv)")
    parser.add_argument(
        "--profile_result_path",
        type=str,
        default=os.path.join(CURDIR, f"ml_profile_{args.version}.csv") 
            if 'args' in locals() else os.path.join(CURDIR, "ml_profile.csv"),
        help="Output CSV for profiling summary (default: ./ml_profile_<version>.csv)"
    )
    parser.add_argument(
        "--summary_txt",
        type=str,
        default=os.path.join(CURDIR, f"run_summary_{args.version}.txt") 
            if 'args' in locals() else os.path.join(CURDIR, "run_summary.txt"),
        help="Output TXT summary (default: ./run_summary_<version>.txt)"
    )
    parser.add_argument("--file_decomposition_output_directory", type=str, default=os.path.join(CURDIR, "decomposed"),
                        help="Directory to materialize source files (default: ./decomposed)")
    parser.add_argument("--thread_num", type=int, default=25, help="Max worker threads (default: 25)")
    parser.add_argument("--gcc_command", type=str, default="gcc -o {output_file} {input_file} {flags}",
                        help="GCC command template")
    parser.add_argument("--default_flags", type=str, default="-O2",
                        help="Default GCC flags (default: -O2)")
    parser.add_argument("--compile_timeout", type=int, default=30, help="Compile timeout seconds (default: 30)")
    parser.add_argument("--run_timeout", type=int, default=30, help="Run timeout seconds (default: 30)")
    return parser

args = build_parser().parse_args()

# Derive rs if not given
if args.rs is None:
    args.rs = f"colv{args.version}"

def rdtsc():
    # Access rdtsc through inline assembly using ctypes
    return rdtsc_lib.rdtsc()  # Example for simplicity

os.environ["MALLOC_CONF"] = "background_thread:false,dirty_decay_ms:0,muzzy_decay_ms:0"

Path(args.profile_result_path).parent.mkdir(parents=True, exist_ok=True)
Path(args.summary_txt).parent.mkdir(parents=True, exist_ok=True)
Path(args.file_decomposition_output_directory).mkdir(parents=True, exist_ok=True)


######################################### start processing #########################################
data = pd.read_csv(args.code_path)

thread_num = args.thread_num
gcc_command = args.gcc_command
default_flags = args.default_flags
file_decomposition_output_directory = args.file_decomposition_output_directory
compilation_results = []
lock = threading.Lock()

def get_total_memory():
    try:
        mem_info = psutil.virtual_memory()
        return mem_info.total  # Total memory capacity in bytes
    except Exception as e:
        print(f"Could not determine total memory capacity: {e}")
    return None

def process_file(row):
    file_name = row['file_name']
    repo_name = row['repo_name']
    file_path = row['path']
    code = row['code']
    unique_id = row['unique_id']

    # Step 1: Decompose the Code into a File
    full_dir_path = os.path.join(file_decomposition_output_directory, repo_name, os.path.dirname(file_path))
    os.makedirs(full_dir_path, exist_ok=True)
    full_file_path = os.path.join(file_decomposition_output_directory, repo_name, file_path)
    with open(full_file_path, 'w') as code_file:
        code_file.write(code)

    # Step 2: Compile, Execute, and Profile the Code
    output_file_path = os.path.join(file_decomposition_output_directory, os.path.basename(full_file_path).replace('.c', ''))
    compile_command = gcc_command.format(output_file=output_file_path, input_file=full_file_path, flags=default_flags)

    result = subprocess.run(compile_command, shell=True, check=True, stdout=subprocess.PIPE, stderr=subprocess.PIPE, timeout=30)
    profiling_data, error = collect_profiling_data(output_file_path)
    
    result_entry = {
        'unique_id': unique_id
    }
    
    if profiling_data:
        result_entry.update(profiling_data)
    with lock:
        compilation_results.append(result_entry)

#core_counter = 0
try:
    total_cores = os.cpu_count()
except:
    total_cores = 1
    
# Function to Collect Profiling Data
def collect_profiling_data(executable_path):
    #global core_counter
    metrics = {
        'execution_time_cycles': None,
        'instruction_count': None,
        'cpi': None,
        'I1mr': None,  # Instruction cache level 1 misses
        'ILmr': None,  # Instruction cache lower-level misses
        'Dr': None,    # Data reads
        'Dw': None,    # Data writes
        'D1mr': None,  # Level 1 data read misses
        'D1mw': None,  # Level 1 data write misses
        'DLmr': None,  # Lower-level data read misses
        'DLmw': None,  # Lower-level data write misses
        'cpu_fre': None,
        'execution_time': None,
        'total_memory': None,
        'instruction_cache_miss_rate': None,
        'data_cache_miss_rate': None
    }
    if not os.access(executable_path, os.X_OK):
        print(f"Permission denied for executing: {executable_path}")
        return metrics, "Permission Denied"

    try:
        start = time.perf_counter()
        start_cycles = rdtsc()
        result = subprocess.run([executable_path], check=True, stdout=subprocess.PIPE, stderr=subprocess.PIPE, timeout=30)
        end_cycles = rdtsc()
        end = time.perf_counter()
        elapsed_time = end - start
        cycles = end_cycles - start_cycles
        metrics['total_memory'] = get_total_memory() 
        if elapsed_time > 0:
            metrics['execution_time_cycles'] = cycles
            metrics['cpu_fre'] = cycles / elapsed_time
            metrics['execution_time'] = elapsed_time 
        #gc.collect()
    except (subprocess.CalledProcessError, subprocess.TimeoutExpired, psutil.NoSuchProcess):
        print(f"Execution failed for {executable_path}")
        return
    
    unique_cachegrind_out = f"cachegrind_{os.path.basename(executable_path)}_{time.time()}.out"
    cachegrind_command = f"valgrind --tool=cachegrind --cachegrind-out-file={unique_cachegrind_out} {executable_path}"
    try:
        subprocess.run(cachegrind_command, shell=True, check=True, stdout=subprocess.PIPE, stderr=subprocess.PIPE, timeout=30)
        with open(unique_cachegrind_out, 'r') as file:
            cachegrind_output = file.read()
            cache_metrics = parse_cachegrind_summary(cachegrind_output)
            metrics.update(cache_metrics)
        os.remove(unique_cachegrind_out)
    except (subprocess.CalledProcessError, subprocess.TimeoutExpired, FileNotFoundError):
        print(f"Cachegrind profiling failed for {executable_path}")
    
    if metrics['execution_time_cycles'] and metrics['instruction_count']:
        metrics['cpi'] = metrics['execution_time_cycles'] / metrics['instruction_count']

    if metrics['instruction_count'] > 0:
        metrics['instruction_cache_miss_rate'] = (metrics['I1mr'] + metrics['ILmr']) / metrics['instruction_count']
    if (metrics['Dr'] + metrics['Dw']) > 0:
        metrics['data_cache_miss_rate'] = (metrics['D1mr'] + metrics['DLmr'] + metrics['D1mw'] + metrics['DLmw']) / (metrics['Dr'] + metrics['Dw'])
    return metrics, None

# Function to parse cachegrind summary based on provided summary line
def parse_cachegrind_summary(cachegrind_output):
    events_line = "events: Ir I1mr ILmr Dr D1mr DLmr Dw D1mw DLmw"
    summary_line_match = re.search(r'summary:\s+([\d\s]+)', cachegrind_output)
    if summary_line_match:
        summary_line = summary_line_match.group(1)
        event_names = events_line.split()[1:]
        summary_values = summary_line.split()
        metrics = {}
        for event, value in zip(event_names, summary_values):
            metrics[event] = int(value)
        metrics_summary = {
            'instruction_count': metrics.get('Ir', 0),
            'I1mr': metrics.get('I1mr', 0),
            'ILmr': metrics.get('ILmr', 0),
            'Dr': metrics.get('Dr', 0),
            'Dw': metrics.get('Dw', 0),
            'D1mr': metrics.get('D1mr', 0),
            'D1mw': metrics.get('D1mw', 0),
            'DLmr': metrics.get('DLmr', 0),
            'DLmw': metrics.get('DLmw', 0)
        }
        return metrics_summary
    else:
        print("Failed to extract cachegrind summary from output.")
        return {}

with ThreadPoolExecutor(max_workers=thread_num) as executor:
    futures = [executor.submit(process_file, row) for _, row in data.iterrows()]
    for future in as_completed(futures):
        pass
          
compilation_summary_df = pd.DataFrame(compilation_results)

sorted_compilation_summary_df = compilation_summary_df.sort_values(
    by=[
        'execution_time_cycles', 
        'instruction_count', 
        'cpi', 
        'I1mr', 'ILmr', 'Dr', 'Dw', 'D1mr', 'D1mw', 'DLmr', 'DLmw'
    ]
)

sorted_compilation_summary_df.to_csv(args.profile_result_path, index=False)
print(f"Compilation and execution summary saved at: {args.profile_result_path}")

with open(args.summary_txt, 'w') as f:
    f.write("DataFrame Shape: {}\n".format(sorted_compilation_summary_df.shape))
    f.write("Descriptive Statistics:\n")
    f.write(sorted_compilation_summary_df.describe().to_string())
    f.write("\n")
    f.write("head")
    f.write(sorted_compilation_summary_df.head(5).to_string())

print("Summary statistics saved to:", args.summary_txt)


