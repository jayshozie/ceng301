# CENG301, Fall 2025 (My Grade: 100%)

## Homework Assignment I

> [!IMPORTANT]
> Due: **23.59, Nov. 9th, 2025**

## Description

In this homework, you will implement a dynamic array-like data structure named
`PreciseSizedArrayList`. A key feature of this structure is that its capacity is
always equal to its size. This means that for every element addition or removal,
you must reallocate a new array of the exact required size and copy the elements
over. This exercise is designed to deepen your understanding of dynamic memory
management in C++.

The elements of this list are integers. You will implement several
functionalities to manipulate this list, as well as a simulation function that
uses the list's size to simulate a circular journey.

You're required to implement the functionalities below. Direct use of any STL
containers such as `vector` or `list` is strictly prohibited and will result in
a grade of zero.

## Functional Requirements

Implement the following member functions for the `PreciseSizedArrayList` class.

1. **`PreciseSizedArrayList()` (5 points):** Constructor. Initializes an empty
list (size is 0 and data pointer is null).

2. **`void add(int index, int value)` (10 points):** Inserts the given `value`
at the specified `index`. Dynamically creates a new array with a size of
`current_size + 1`. It copies elements, inserts the new `value` at the correct
position, and shifts the subsequent elements. If the `index` is negative, it
should be interpreted as an offset from the end of the list (e.g. `-1` is the
end of the list, `-2` is one before the end). If `index` is `0`, it inserts at
the beginning. If `index` is `-1` or equal to `size`, it appends to the end. If
the resolved `index` is out of bounds, the function should have no effect.
Finally, it deallocates the old array.

3. **`void remove(int index)` (15 points):** Removes the element at the
specified `index`. If the `index` is negative, it should be interpreted as an
offset from the end of the list (e.g. `-1` is the last element). It then creates
a new, smaller array, copies the remaining elements, and deallocates the old
array. If the resolved index is out of bounds (e.g. `index` `5` for a list of
size `4`, or `index` `-6` for a list of size `4`), the function should have no
effect.

4. **`void changeValue(int index, int new_value)` (10 points):** Changes the
element at the specified `index` to `new_value`. If the `index` is negative, it
should be interpreted as an offset from the end (e.g. `-1` is the last element).
If the resolved index is out of bounds, the function should have no effect.

5. **`void reverse()` (10 points):** Reverses the order of the elements within
the array in-place.

6. **`double getAverageValue() const` (10 points):** Calculates and returns the
average of all integer values in the list. If the list is empty, it should
return `0.0`.

7. **`void simulateJourney(int step_one, int step_two) const` (15 points):**
Implements **The Adventurers' Journey** simulation.
    - Both adventurers start at `index` `0`.
    - The function must print the position of each adventurer at each step,
    starting step `0` (the initial position). The format for each step should be
    `Step [k]: A1 at [idx1], A2 at [idx2]`
    - In each turn (starting from step 1), Adventurer 1 moves forward by
    `step_one`, and Adventurer 2 moves forward by `step_two`.
    - All movements are circular
    (i.e. `new_index = (current_index + steps) % size`).
    - The simulation stops as soon as they meet at the same index **after the
    starting point**. The meeting at step 0 does not count. The first meeting at
    any step `k > 0` terminates the simulation.
    - If the list is empty, the function should print `List is empty.` and
    return immediately.
    - **You are guaranteed, for all test cases, the given `step_one` and
    `step_two` values will eventually cause the adventurers to meet at a step
    `k > 0`.** You do not need to implement any special checks for cases where
    they might loop forever.
    - Put a newline at the end of the output.

8. **`void printList()` const (10 points):** A helper function to display the
contents of the list. Each node should be printed on a newline in the format:
`Index: [i], Value: [v]`. Put a newline at the end of the output.

9. **Report (15 points):** You will also upload a report worth 15 points.
Details about the report are given below.

## IMPORTANT NOTES

> [!IMPORTANT]
> **<u>Do not start your homework before reading these notes!!!</u>**

1. You ARE NOT ALLOWED to modify the given header files. You MUST use the
specified dynamic reallocation approach for your implementation. You will get no
points if you use fixed-sized arrays or any other data structures such as
vectors, lists, sets, or maps from the standard library.

2. Moreover, you ARE NOT ALLOWED to use any global variables or global
functions.

3. Your output for each operation MUST exactly match the format shown in the
example output (e.g. for `printList` and `simulateJourney`). Otherwise, you will
not receive points for that part.

4. Using the C++ STL (Standard Template Library) is strictly forbidden.

5. For this assignment, you must submit two files. These are separate activities
in ODTÜClass to submit code and report.
    - `PreciseSizedArrayList.cpp`: Your implementation file for all the member
    functions of the `PreciseSizedArrayList` class. Codes should be submitted
    through the VPL activity on ODTÜClass.
    - `report_studentID.pdf`: A short report containing complexity analysis and
    runtimes.
