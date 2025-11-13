#!/bin/bash
#SBATCH --job-name=                  # Job name
#SBATCH --output=.log                # Standard output log
#SBATCH --error=_error.log                  # Standard error log
#SBATCH --partition=batch                  # Partition to submit to
#SBATCH --mem=240G                         # Memory request
#SBATCH -N                               # Request 1 node
#SBATCH -n                                # Request 1 task
#SBATCH -c                              # Request 30 CPU cores
#SBATCH --time=24:00:00                    # Time limit (optional)


source xxx/conda.sh
conda activate your_env_name

python your_script.py



