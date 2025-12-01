# AI Coding Agent Instructions for LeetCode Algorithm Repository

## Project Overview
This is a LeetCode algorithm solutions repository containing C++ and Python implementations of various data structure and algorithm problems. Each file is named by problem number (e.g., `T1.cpp` for problem 1, `T394.cpp` for problem 394).

## File Organization & Naming Convention
- **File naming**: `T{PROBLEM_NUMBER}.cpp` or `T{PROBLEM_NUMBER}.py` (e.g., `T20.cpp`, `T70_palouti.py`)
- **Dual implementations**: Many problems have both `.cpp` and `.py` variants for algorithm comparison
- **Chinese comments**: Filenames and key comments are in Chinese (e.g., "递归实现逆序输出数组" = "recursive reverse array output")

## Code Structure Patterns

### Class-Based Solution Pattern
All solutions follow a `Solution` class structure with public methods:
```cpp
class Solution {
public:
    TYPE methodName(PARAMETERS) { /* implementation */ }
};
```
- Example: `T1.cpp` uses `vector<int> twoSum(vector<int> &nums, int target)`
- Example: `T20.cpp` uses `bool isValid(string s)`

### Multi-Solution Approach
Files often contain multiple solution implementations with increasing optimization:
- **T394.cpp**: Shows `Solution` (unoptimized recursive) → `Solution2` (optimized using global position pointer)
- **T1.cpp**: Includes commented alternative implementations (hash map approach vs. sorting)
- Pattern: Always document the trade-offs between solutions in comments

### Common Data Structures
- **Vectors**: For dynamic arrays (`vector<int>`, `vector<string>`)
- **Stack**: For bracket matching, DFS-like problems (e.g., `T20.cpp` uses `stack<char>`)
- **Linked Lists**: Custom `ListNode` struct with val and next pointer (e.g., `T1_huiwen.cpp`)
- **Hash Maps**: For lookups (e.g., `unordered_map<char, char>` in `T20.cpp`)

## Problem-Solving Patterns

### Dynamic Programming / Mathematical Problems
- **T70_palouti** (climbing stairs): Use space-optimized iteration rather than recursion
- Pattern: Track only necessary state (two previous values for Fibonacci-like problems)

### String/Array Recursion
- **T394** (decode string): Use global position pointer to avoid substring copying overhead
- Pattern: Optimize by indexing into original string instead of creating substrings

### Bracket/Parenthesis Validation
- **T20** (valid parentheses): Use stack + hash map for O(1) bracket matching
- Pattern: Store closing→opening bracket mappings for efficient validation

### Linked List Operations
- **T1_huiwen** (palindrome check): Convert to vector for simpler comparison
- Pattern: Trade space for simplicity when applicable

## Build & Execution

### Compilation Commands
C++ files compile with standard g++ or clang++:
- **Debug build**: `g++ -g T{NUMBER}.cpp -o T{NUMBER}` (generates executable + dSYM)
- **Direct execution**: `./T{NUMBER}` after compilation

### Testing Pattern
Solutions include `main()` functions with test cases:
```cpp
int main() {
    Solution sol;
    // Test cases with expected outputs
    cout << sol.methodName(testInput) << endl;
    return 0;
}
```
- No external test framework; manual testing via direct execution
- dSYM directories (.dSYM/) enable debugging with `lldb`

## Python Specifics
- Python files (`.py`) provide equivalent solutions to C++ versions
- Example: `T70_palouti.py` implements climbing stairs with tuple unpacking
- Both languages solve identical algorithmic problems for comparison/learning

## Key Development Workflows

### Adding New Solutions
1. Create file: `T{PROBLEM_NUMBER}.cpp` or `T{PROBLEM_NUMBER}.py`
2. Use `Solution` class pattern with public method
3. Include detailed comments in Chinese explaining approach
4. Add comprehensive test cases in `main()`
5. Compile to verify: `g++ -g T{NUMBER}.cpp -o T{NUMBER}`

### Optimization Patterns
- Avoid string copying in recursive functions; use position pointers instead (T394 example)
- Use space-optimized solutions for DP problems; track only essential state (T70 example)
- Prefer hash maps for O(1) lookups in validation problems (T20 example)

### Debugging
- Compile with `-g` flag for debugging symbols
- Use lldb: `lldb ./T{NUMBER}` then set breakpoints and step through
- dSYM directories automatically created; enables IDE debugging integration

## Language-Specific Notes
- **C++**: Primary language; uses `#include <iostream>`, `#include <vector>`, etc.
- **Python**: Secondary; equivalent implementations for comparison
- Mix languages only for specific algorithm variations (not required for all problems)

## Conventions NOT to Follow
- Do NOT create separate optimization files; put all solutions in one file with `Solution`, `Solution2`, etc.
- Do NOT use external libraries beyond STL (C++) or standard library (Python)
- Do NOT add verbose documentation files; let well-commented code speak for itself
