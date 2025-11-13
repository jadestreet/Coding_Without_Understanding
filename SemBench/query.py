import os
import json
import random
import networkx as nx
from itertools import permutations
from collections import Counter

with open("config.json", "r") as f:
    config = json.load(f)

TYPE_KERNELS = config.get("type_kernels", "loop3_1000")
BASE_DIR = os.path.join(os.getcwd(), "data")
QUERY_DIR = os.path.join(BASE_DIR, TYPE_KERNELS, "queries")
GROUND_TRUTH_DIR = os.path.join(BASE_DIR, TYPE_KERNELS, "ground_truth")
PARSED_CODE_DIR = os.path.join(BASE_DIR, TYPE_KERNELS, "parsed_code")

os.makedirs(QUERY_DIR, exist_ok=True)
os.makedirs(GROUND_TRUTH_DIR, exist_ok=True)

max_query = 2  # Maximum queries per category
DISAMBIGUATE_BY = 'line'  # Disambiguation method for variable names ('line' or 'code')

# ----------------------------
# Flexible Templates per Category
# ----------------------------
TEMPLATES = {
    "function_reachability": [
        lambda src, dst: f"Can function '{src}' eventually call function '{dst}'?",
        lambda src, dst: f"Is there a call path from function '{src}' to function '{dst}'?"
    ],
    "loop_reachability": [
        lambda cond: f"Can the loop with condition '{cond}' be skipped entirely?",
        lambda cond: f"Is it possible that the loop with condition '{cond}' is never executed?"
    ],
    "dominators": [
        lambda cond: (
            f"In the control‑flow graph, does the loop‑header block for condition "
            f"'{cond}' strictly dominate every block in the loop body?"
        ),
        lambda cond: (
            f"For condition '{cond}', must all paths from function entry to any "
            f"loop‑body statement pass through the loop header?"
        )
    ],
    "data_dependency": [
        lambda var: f"Is variable '{var}' used after its definition?",
        lambda var: f"Does the value assigned to '{var}' affect subsequent computations?"
    ],
    "liveness": [
        lambda func, var: f"Is variable '{var}' live at the end of function '{func}'?",
        lambda func, var: f"Does variable '{var}' remain in use at the end of function '{func}'?"
    ],
    "dead_code": [
        lambda code: f"Is the statement '{code}' unreachable during execution?",
        lambda code: f"Can the statement '{code}' be considered dead code because it is never executed?"
    ],
    "pointer_aliasing": [
        lambda p1, p2: f"Can pointer '{p1}' alias pointer '{p2}'?",
        lambda p1, p2: f"Do pointers '{p1}' and '{p2}' refer to the same memory location?"
    ]
}

# Complementary templates (alternate phrasing) to balance queries.
COMPLEMENTARY_TEMPLATES = {
    "function_reachability": [
        lambda src, dst: f"Is it impossible for function '{src}' to reach function '{dst}'?"
    ],
    "loop_reachability": [
        lambda cond: f"Is the loop with condition '{cond}' always executed?"
    ],
    "dominators": [
        lambda cond: (
            f"Is there at least one path that reaches the body of the loop "
            f"with condition '{cond}' without passing through its header block?"
        )    
    ],
    "data_dependency": [
        lambda var: f"Does the computation remain unaffected if '{var}' is not used after its definition?"
    ],
    "liveness": [
        lambda func, var: f"Is variable '{var}' dead at the end of function '{func}'?"
    ],
    "dead_code": [
        lambda code: f"Is it guaranteed that the statement '{code}' will never execute?"
    ],
    "pointer_aliasing": [
        lambda p1, p2: f"Is it guaranteed that pointers '{p1}' and '{p2}' do not alias?"
    ]
}

# ----------------------------
# Helper Functions
# ----------------------------
def load_parsed_code(file_name):
    parsed_path = os.path.join(PARSED_CODE_DIR, f"{file_name}.json")
    if os.path.exists(parsed_path):
        with open(parsed_path, "r") as f:
            return json.load(f)
    return None

def build_call_graph(parsed_code):
    G = nx.DiGraph()
    functions = parsed_code.get("functions", [])
    for func in functions:
        func_name = func.get("name")
        if func_name:
            G.add_node(func_name)
            for call in func.get("calls", []):
                G.add_edge(func_name, call)
    return G

# ----------------------------
# Query Generator Functions
# ----------------------------
def generate_function_reachability_queries(parsed_code):
    queries, ground_truth = [], []
    call_graph = build_call_graph(parsed_code)
    functions = list(call_graph.nodes)
    if len(functions) < 2:
        print("Not enough functions for reachability queries.")
        return queries, ground_truth
    pairs = list(permutations(functions, 2))
    random.shuffle(pairs)
    pos_count, neg_count = max_query, max_query
    for src, dst in pairs:
        if pos_count == 0 and neg_count == 0:
            break
        reachable = nx.has_path(call_graph, src, dst)
        if reachable and pos_count > 0:
            template = random.choice(TEMPLATES["function_reachability"])
            q = template(src, dst)
            queries.append(q)
            ground_truth.append(True)
            pos_count -= 1
        elif not reachable and neg_count > 0:
            template = random.choice(TEMPLATES["function_reachability"])
            q = template(src, dst)
            queries.append(q)
            ground_truth.append(False)#Should be true or change template
            neg_count -= 1
    if queries and len(set(ground_truth)) < 2:
        print("Warning: Only one type of answer generated in function reachability queries.")
    return queries, ground_truth

def generate_loop_reachability_queries(parsed_code):
    queries, ground_truth = [], []
    loops = parsed_code.get("loops", [])
    if not loops:
        print("No loops found for loop reachability queries.")
        return queries, ground_truth

    yes_skip, yes_always = max_query, max_query
    for loop in loops:
        if yes_skip == 0 and yes_always == 0:
            break

        cond = loop.get("cond", "unknown")
        reachable = loop.get("reachable", True)

        if not reachable and yes_skip > 0:
            tmpl = random.choice(TEMPLATES["loop_reachability"])
            q = tmpl(cond)
            queries.append(q)
            ground_truth.append(True)
            yes_skip -= 1

        elif reachable and yes_skip > 0:
            tmpl = random.choice(TEMPLATES["loop_reachability"])
            q = tmpl(cond)
            queries.append(q)
            ground_truth.append(False)
            yes_skip -= 1

        if reachable and yes_always > 0:
            tmpl = random.choice(COMPLEMENTARY_TEMPLATES["loop_reachability"])
            q = tmpl(cond)
            queries.append(q)
            ground_truth.append(True)
            yes_always -= 1

        elif not reachable and yes_always > 0:
            tmpl = random.choice(COMPLEMENTARY_TEMPLATES["loop_reachability"])
            q = tmpl(cond)
            queries.append(q)
            ground_truth.append(False)
            yes_always -= 1

    if queries and len(set(ground_truth)) < 2:
        print("Warning: Only one type of answer generated in loop reachability queries.")
    return queries, ground_truth

def generate_loop_dominator_queries(parsed_code):
    queries, ground_truth = [], []
    loops = parsed_code.get("loops", [])
    if not loops:
        print("No loops found for dominator queries.")
        return queries, ground_truth
    pos_count, neg_count = max_query, max_query
    for loop in loops:
        if pos_count == 0 and neg_count == 0:
            break
        condition = loop.get("cond", "unknown")
        if loop.get("dominates_body", False) and pos_count > 0:
            template = random.choice(TEMPLATES["dominators"])
            q = template(condition)
            queries.append(q)
            ground_truth.append(True)
            pos_count -= 1
        elif not loop.get("dominates_body", False) and neg_count > 0:
            template = random.choice(COMPLEMENTARY_TEMPLATES["dominators"])
            q = template(condition)
            queries.append(q)
            ground_truth.append(False)
            neg_count -= 1
    if queries and len(set(ground_truth)) < 2:
        print("Warning: Only one type of answer generated in dominator queries.")
    return queries, ground_truth

def generate_variable_dependency_queries(parsed_code):
    queries, ground_truth = [], []
    dependencies = parsed_code.get("dependencies", [])
    if not dependencies:
        print("No variable dependencies found.")
        return queries, ground_truth
    var_counts = Counter([dep.get("var", "unknown") for dep in dependencies])
    pos_count, neg_count = max_query, max_query
    for dep in dependencies:
        if pos_count == 0 and neg_count == 0:
            break
        var_name = dep.get("var", "unknown")
        if var_counts[var_name] > 1:
            if DISAMBIGUATE_BY == 'line':
                var_id = f"{var_name} (line {dep.get('line', '?')})"
            elif DISAMBIGUATE_BY == 'code':
                snippet = None
                for stmt in parsed_code.get("dead_code", []):
                    if stmt.get("line") == dep.get("line"):
                        snippet = stmt.get("code", "").strip()
                        break
                if snippet:
                    var_id = f"{var_name} ({snippet})"
                else:
                    var_id = f"{var_name} (line {dep.get('line', '?')})"
            else:
                var_id = var_name
        else:
            var_id = var_name
        if dep.get("used_after_definition", False) and pos_count > 0:
            template = random.choice(TEMPLATES["data_dependency"])
            q = template(var_id)
            queries.append(q)
            ground_truth.append(True)
            pos_count -= 1
        elif not dep.get("used_after_definition", False) and neg_count > 0:
            template = random.choice(COMPLEMENTARY_TEMPLATES["data_dependency"])
            q = template(var_id)
            queries.append(q)
            ground_truth.append(False)
            neg_count -= 1
    if queries and len(set(ground_truth)) < 2:
        print("Warning: Only one type of answer generated in variable dependency queries.")
    return queries, ground_truth

def generate_liveness_queries(parsed_code):
    """
    Create yes/no questions about whether a variable is live at the end
    of a specific function. Uses the per‑function live_out map produced by the parser.
    """
    queries, ground_truth = [], []
    functions = parsed_code.get("functions", [])
    if not functions:
        return queries, ground_truth
    # Count occurrences of each variable across all functions for disambiguation
    var_counts = Counter([var for fn in functions for var in fn.get("live_out", {})])
    # Map function names to their definition line (from dead_code listing)
    func_def_lines = {}
    code_lines = parsed_code.get("dead_code", [])
    for stmt in code_lines:
        code_text = stmt.get("code", "")
        if not code_text:
            continue
        # Identify function definition lines by pattern: line ends with ')' (no ';')
        if code_text.endswith(")") and not code_text.endswith(");"):
            for fn in functions:
                name = fn.get("name")
                if name and name in code_text:
                    func_def_lines[name] = stmt.get("line")
    for i, fn in enumerate(functions):
        fn_name = fn.get("name")
        if not fn_name:
            continue
        live_map = fn.get("live_out", {})
        if not live_map:
            continue
        # Determine next function's start line for range end
        if i < len(functions) - 1:
            next_fn_name = functions[i+1].get("name")
            next_start = func_def_lines.get(next_fn_name, float('inf'))
        else:
            next_start = float('inf')
            if code_lines:
                next_start = code_lines[-1].get("line", float('inf')) + 1
        f_start = func_def_lines.get(fn_name, 0)
        for var, is_live in live_map.items():
            if var_counts[var] > 1:
                if DISAMBIGUATE_BY == 'line':
                    decl_line = None
                    for dep in parsed_code.get("dependencies", []):
                        line_no = dep.get("line")
                        if dep.get("var") == var and line_no and line_no >= f_start and line_no < next_start:
                            if decl_line is None or line_no < decl_line:
                                decl_line = line_no
                    if decl_line:
                        var_id = f"{var} (line {decl_line})"
                    else:
                        var_id = var
                elif DISAMBIGUATE_BY == 'code':
                    decl_line = None
                    for dep in parsed_code.get("dependencies", []):
                        line_no = dep.get("line")
                        if dep.get("var") == var and line_no and line_no >= f_start and line_no < next_start:
                            if decl_line is None or line_no < decl_line:
                                decl_line = line_no
                    snippet = None
                    if decl_line:
                        for stmt in code_lines:
                            if stmt.get("line") == decl_line:
                                snippet = stmt.get("code", "").strip()
                                break
                    if snippet:
                        var_id = f"{var} ({snippet})"
                    elif decl_line:
                        var_id = f"{var} (line {decl_line})"
                    else:
                        var_id = var
                else:
                    var_id = var
            else:
                var_id = var
            template = random.choice(TEMPLATES["liveness"])
            question = template(fn_name, var_id)
            queries.append(question)
            ground_truth.append(is_live)
            if len(queries) >= max_query:
                break
        if len(queries) >= max_query:
            break
    if queries and len(set(ground_truth)) < 2:
        print("Warning: Only one type of answer generated in liveness queries.")
    return queries, ground_truth

def generate_dead_code_queries(parsed_code):
    queries, ground_truth = [], []
    statements = parsed_code.get("dead_code", [])
    if not statements:
        print("No statements found for dead code queries.")
        return queries, ground_truth
    pos_count, neg_count = max_query, max_query
    for stmt in statements:
        if pos_count == 0 and neg_count == 0:
            break
        code_snippet = stmt.get("code", "").strip()
        if stmt.get("dead", False) and pos_count > 0: 
            template = random.choice(TEMPLATES["dead_code"])
            q = template(code_snippet)
            queries.append(q)
            ground_truth.append(True)
            pos_count -= 1
        elif not stmt.get("dead", False) and neg_count > 0:
            template = random.choice(COMPLEMENTARY_TEMPLATES["dead_code"])
            q = template(code_snippet)
            queries.append(q)
            ground_truth.append(False)
            neg_count -= 1
    if queries and len(set(ground_truth)) < 2:
        print("Warning: Only one type of answer generated in dead code queries.")
    return queries, ground_truth

def generate_queries(parsed_code):
    queries, ground_truth = {}, {}
    fq, ft = generate_function_reachability_queries(parsed_code)
    queries["function_reachability"] = fq
    ground_truth["function_reachability"] = ft

    lq, lt = generate_loop_reachability_queries(parsed_code)
    queries["loop_reachability"] = lq
    ground_truth["loop_reachability"] = lt

    ldq, ldt = generate_loop_dominator_queries(parsed_code)
    queries["dominators"] = ldq
    ground_truth["dominators"] = ldt

    vdq, vdt = generate_variable_dependency_queries(parsed_code)
    queries["data_dependency"] = vdq
    ground_truth["data_dependency"] = vdt

    lq2, lt2 = generate_liveness_queries(parsed_code)
    queries["liveness"] = lq2
    ground_truth["liveness"] = lt2

    dq, dt = generate_dead_code_queries(parsed_code)
    queries["dead_code"] = dq
    ground_truth["dead_code"] = dt

    return queries, ground_truth

def ensure_balanced_queries(queries, ground_truth):
    """
    For each category, if only one type of answer is generated,
    add a complementary query using alternate phrasing (preserving ground truth).
    """
    for category in queries:
        if not queries[category]:
            continue
        if len(set(ground_truth[category])) < 2:
            base_q = queries[category][0].replace("Test Question: ", "").strip()
            comp_q = "Alternate phrasing: " + base_q
            queries[category].append("Test Question: " + comp_q)
            ground_truth[category].append(ground_truth[category][0])
            print(f"Added complementary query in category '{category}' to balance answers.")
    return queries, ground_truth

def process_file(file_name):
    program_name = os.path.splitext(file_name)[0]
    print(f"Processing program: {program_name}")
    parsed_code = load_parsed_code(program_name)
    if not parsed_code:
        return
    queries, ground_truth = generate_queries(parsed_code)
    query_path = os.path.join(QUERY_DIR, f"{program_name}.json")
    truth_path = os.path.join(GROUND_TRUTH_DIR, f"{program_name}.json")
    with open(query_path, "w") as f:
        json.dump(queries, f, indent=4)
    with open(truth_path, "w") as f:
        json.dump(ground_truth, f, indent=4)
    print(f"Queries & ground truth saved for {program_name}")

if __name__ == "__main__":
    from concurrent.futures import ThreadPoolExecutor, as_completed
    files = [f for f in os.listdir(PARSED_CODE_DIR) if f.endswith(".json")]
    with ThreadPoolExecutor() as executor:
        futures = {executor.submit(process_file, file_name): file_name for file_name in files}
        for future in as_completed(futures):
            file_name = futures[future]
            try:
                future.result()
            except Exception as e:
                print(f"Error processing {file_name}:", e)
