####################################
# BACKGROUND INFORMATION
####################################
background_info = {
    "function_reachability": (
        "Function_reachability examines whether one function can transitively call another (i.e., if a call path exists)."
    ),
    "loop_reachability": (
        "Loop reachability examines whether a loop is executed during program execution based on its condition and structure. "
    ),
    "dominators": (
        "Dominator analysis in C is about identifying whether certain code sections (like loop headers) must execute before other parts of the loop. "
    ),
    "data_dependency": (
        "Data dependency analysis involves determining if a variable’s defined value is used and influences subsequent computations. "
    ),
    "liveness": (
        "Liveness analysis determines whether a variable’s value is used later in the program. "
    ),
    "dead_code": (        
        "Dead code consists of segments that are never executed, such as code following an unconditional return or unreachable branches. "
    ),
    "pointer_aliasing": (                
        "Pointer aliasing occurs when two or more pointers refer to the same memory location, potentially leading to unexpected behavior. "
    )
}
