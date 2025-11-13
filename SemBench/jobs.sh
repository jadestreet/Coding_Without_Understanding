#!/bin/bash
#SBATCH --job-name=                       # Job name
#SBATCH --output=.log     # Combined stdout
#SBATCH --error=.log # Combined stderr
#SBATCH --partition=batch
#SBATCH -N1
#SBATCH -n1
#SBATCH -c60
#SBATCH --mem=200G
#SBATCH --gpus=mi210:4
#SBATCH --time=24:00:00

# — Environment setup — TODO: change it to your own conda environment path
source xxxx/anaconda3/etc/profile.d/conda.sh
conda activate xxxx
cd xxx/SemBench
export OMP_NUM_THREADS=8
export TRANSFORMERS_NO_ADVISORY_WARNINGS=1
# — List of models to sweep through —

MODELS=(
  "meta-llama/Llama-3.1-8B-Instruct"
  "Qwen/Qwen3-14B"
  "Qwen/Qwen2.5-Coder-14B-Instruct"
  "microsoft/Phi-4-reasoning"  
  "mistralai/Mistral-7B-Instruct-v0.3"
  "mistralai/Mamba-Codestral-7B-v0.1"
  "deepseek-ai/DeepSeek-Coder-V2-Lite-Instruct"
  "deepseek-ai/deepseek-coder-7b-instruct-v1.5"
  "deepseek-ai/DeepSeek-R1-Distill-Qwen-7B"
  "bigcode/starcoder2-7b"
  "codellama/CodeLlama-13b-Instruct-hf"
  "codellama/CodeLlama-7b-Instruct-hf"
)
# — Loop over each model, one after another —
for MODEL_NAME in "${MODELS[@]}"; do
  echo "[$(date +'%Y-%m-%d %H:%M:%S')] === Starting run for model: $MODEL_NAME ==="
  
  torchrun \
    --nproc_per_node=4 \
    3llm_sem_simple_fast3.py \
      --model_name "$MODEL_NAME" \
      --batch_size 24 \
      --max_tokens 64 \
      --temperature 0.0
  echo "[$(date +'%Y-%m-%d %H:%M:%S')] === Finished run for model: $MODEL_NAME ==="
  echo
done