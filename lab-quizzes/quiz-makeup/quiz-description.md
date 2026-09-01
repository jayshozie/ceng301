# Make-up Exam (Didn't Take It)

- **Instructions:**
    - You are required to solve **ALL 3 tasks**. You may define
    your own helper functions for any question.
    - You may use `std::pow(base, exp)` to find `base^exp`.

## Task 1: Dynamic 2D Array Filtering (33 Points)

- **Problem Description:** You are required to implement a function that
processes a dynamically allocated 2D integer array (matrix). The goal is to
filter this matrix by removing rows that do not meet a specific criteria.
Specifically, you must calculate the **sum of all integers** within each row. If
this sum is strictly greater than the provided `threshold` value, the row is
preserved. If the sum is less than or equal to the threshold, the row is
discarded.

- **Memory Management Constraints:** Since this course emphasizes low-level data
structure management, the usage of high-level containers such as `std::vector`
is **STRICTLY FORBIDDEN** for this task. You must perform manual memory
allocation:

1. You will likely need a **two-pass approach**. First, iterate through the
matrix to count how many rows satisfy the condition.
2. Allocate a new array of pointers (`int**`) exactly sized for the valid rows.
3. Iterate again to allocate memory for each valid row's columns (`new int[]`)
and copy the data element by element.
4. Finally, update the reference parameter `newRows` so the caller knows the
size of the new matrix.


