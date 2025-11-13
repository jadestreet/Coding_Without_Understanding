import re
from typing import Optional, List
INSTRUCTION = "Given the C code and background information, you should solve this problem step by step briefly and your response should end with an option between \"[Final answer: yes]\" or \"[Final answer: no]\"."
INSTRUCTION_simple = "Given the C code and background information, answer each test question with an option between [yes] and [no]."
INSTRUCTION = "Given the C code and background information, your response should start with an option between \"[Final answer: yes]\" or \"[Final answer: no]\" then you should explain your solution step by step briefly."

_BOILERPLATE_RE = re.compile(
    r'(?i)\b(?:yes\s*/\s*no|yes\s+or\s+no)\b[\?\:\.\s]*'
)


_clean_re   = re.compile(r'[^A-Za-z0-9\[\]:\s]')
_prefix_re  = re.compile(r'(?:final\s*)?answer\s*:', flags=re.IGNORECASE)
_bracket_re = re.compile(r'\[final\s*answer:\s*(?:yes|no)\]', flags=re.IGNORECASE)
_verdict_re = re.compile(r'(?:final\s*)?answer\s*:\s*(yes|no)', flags=re.IGNORECASE)
_word_no  = re.compile(r'\bno\b')
_word_yes = re.compile(r'\byes\b')

def parse_llm_response(response: str) -> Optional[bool]:
    cleaned = _clean_re.sub('', response)
    for line in reversed(cleaned.splitlines()):
        low = line.lower()
        # skip any line that doesn't even mention 'answer'
        if 'answer' not in low:
            continue
        # skip lines with >1 bracketed "[Final answer: yes]" or "[Final answer: no]"
        if len(_bracket_re.findall(line)) > 1:
            continue
        # require at least one 'answer:' or 'final answer:' prefix
        if not _prefix_re.search(line):
            continue
        # if the line still literally mentions both 'yes' and 'no', skip
        has_yes = bool(_word_yes.search(line))
        has_no  = bool(_word_no.search(line))
        if has_yes and has_no:
            continue
        # apply your exact verdict regex
        hits = _verdict_re.findall(line)
        if not hits:
            continue
        unique = {h.lower() for h in hits}
        if unique == {'yes'}:
            return True
        if unique == {'no'}:
            return False
    return None


def majority_vote(decisions):
    """
    Given a list of boolean decisions (or Nones), returns the majority decision
    and the ratio of votes for that decision.
    """
    yes_votes = sum(1 for d in decisions if d is True)
    no_votes  = sum(1 for d in decisions if d is False)
    total = yes_votes + no_votes
    if total == 0:
        return None, 0
    if yes_votes >= no_votes:
        return True, yes_votes / total
    else:
        return False, no_votes / total

def construct_input_large(code_file, prompt, category):
    """
    Builds the full prompt for the LLM, including the C code, background info,
    few-shot examples, and the test question.
    """
    input_text = ""
    input_text += INSTRUCTION + "\n\n"
    try:
        from script.prompts.BACKGROUND_new import background_info
    except ImportError:
        background_info = {}
    try:
        with open(code_file, "r") as f:
            code = f.read()
    except Exception as e:
        print(f"Error reading code file {code_file}: {e}")
                
    if background_info.get(category, ""):
        input_text += background_info.get(category, "") + "\n\n"
        
    input_text += "See the C Code and answer the question:\n" + code + "\n\n" + "Test Question: " + prompt 
    
    return input_text

def convert_tensors(obj):
    """
    Recursively converts any torch.Tensor objects in an object to Python scalars/lists.
    (Retained for legacy support; API responses are JSON serializable.)
    """
    try:
        import torch
        if isinstance(obj, torch.Tensor):
            return obj.item() if obj.numel() == 1 else obj.tolist()
    except ImportError:
        pass
    if isinstance(obj, dict):
        return {k: convert_tensors(v) for k, v in obj.items()}
    elif isinstance(obj, list):
        return [convert_tensors(v) for v in obj]
    else:
        return obj