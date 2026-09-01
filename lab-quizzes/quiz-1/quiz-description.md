# CENG301, Fall 2025 - something Lab Quiz (My Grade: 100%)

You are given a header file `PreciseSizedArrayList.h` and a partial
implementation in `PreciseSizedArrayList.cpp`. Your task is to implement the
three (3) empty functions.

## Questions

1. **`PreciseSizedArrayList()` Constructor (30 points)**

Implement the default constructor `PreciseSizedArrayList()`. When a new object
of this class is created, its `size` member must be initialized to `0`, and its
`data` pointer must be initialized to `nullptr` (or `0`). This ensures the list
starts in a valid, empty state.

- **Example Test Case**
```cpp
#include "PreciseSizedArrayList.h"
#include <iostream>

int main()
{
    PreciseSizedArrayList a;
    // We access `size` and `data` directly for this test.
    std::cout << a.size << std::endl;
    std::cout << (void*)a.data << std::endl; // should be 0 (nullptr)
    return 0;
}
```
- **Expected Output**
```console
0
0
```

2. **`void removeByValue(int value)` (35 points):**

Implement the `void removeByValue(int value)` function. This function much
search the list for the **first occurrence** of the given `value`. You are
provided with a helper function: `void removeByIndex(int index)`. Your task is
to find the correct index and call this function.

- **Important Rules:**
    - If the `value` is found at a certain `index`, you must call the provided
    helper function `removeByIndex(int index)` to perform the removal.
    - If the list is empty or the `value` is not found in the list, the function
    should do nothing.

> [!NOTE]
> You do not need to write any code for `new/delete` or array copying yourself.
> Your only job is to find the index and call the helper.

- **Example Test Case**
```cpp
#include "PreciseSizedArrayList.h"
#include <iostream>

int main()
{
    PreciseSizedArrayList a;
    a.add(-1, 10);
    a.add(-1, 20);
    a.add(-1, 30);
    a.add(-1, 20);
    std::cout << "Original list:" << std::endl;
    a.printList();
    a.removeByValue(20); // Remove first '20'
    std::cout << "After removing 20:" << std::endl;
    a.printList();
    a.removeByValue(99); // Value not found
    std::cout << "After attempting to remove 99:" << std::endl;
    a.printList();
    return 0;
}
```
- **Expected Output**
```console
Original list:
Index: 0, Value: 10
Index: 1, Value: 20
Index: 2, Value: 30
Index: 3, Value: 20
After removing 20:
Index: 0, Value: 10
Index: 1, Value: 30
Index: 2, Value: 20
After attempting to remove 99:
Index: 0, Value: 10
Index: 1, Value: 30
Index: 2, Value: 20
```

3. **`double getHarmonicAverage() const` (35 points)**

Implement the `double getHarmonicAverage() const` function. The harmonic mean,
$`H`$, of $`n`$ numbers $`x_1, x_2, x_3, ..., x_n`$ is defined as:
```latex
H = \frac{n}{\sum_{i=1}^{n}{\frac{1}{x_i}}} = \frac{n}{\frac{1}{x_1} + \frac{1}{x_2} + ... + \frac{1}{x_n}}
```
You must calculate and return this value.

> [!NOTE]
> ***A Friendly Guide for `getHarmonicAverage()`***
> - **Translating the Math:** The `n` in the formula is just like your list's
> `size`. The $`x_i`$ simply means "each value in your `data` array", like
> `data[0]`, `data[1]`, etc.
> - **Beware the "Integer Division" Trap:** In C++, dividing two integers (like
> `int/int`) **always results in an integer**. The decimal part is cut off
> (truncated).
>   - **The Trap:** If you write `1/data[i]` (where `data[i]` is 2, 4, or 8),
>   C++ will calculate this as 0 every time, not `0.5` or `0.25`. This will make
>   your sum incorrect.
>   - **The Solution:** To get the correct decimal answer, you must use a
>   `double`. Simply write `1.0 / data[i]` instead. This forces C++ to perform
>   floating-point division, giving you the correct value.

- **Important Rules:**
    - If the list is empty (`size == 0`), you must return `0.0`.
    - If any element in the list is 0, the harmonic mean is mathematically
    undefined (division by zero). For this quiz, if any `value == 0` is present
    in the list, you must also return `0.0`.

- **Example Test Case**
```cpp
#include "PreciseSizedArrayList.h"
#include <iostream>
#include <iomanip> // For setprecision

int main ()
{
    PreciseSizedArrayList a;
    a.add(-1, 2);
    a.add(-1, 4);
    a.add(-1, 8);
    
    PreciseSizedArrayList b; // Empty list
    
    PreciseSizedArrayList c;
    c.add(-1, 1);
    c.add(-1, 0); // Contains zero
    
    std::cout << std::fixed << std::setprecision(4);
    std::cout << "Harmonic Average of List A (2, 4, 8): " << a.getHarmonicAverage() << std::endl;
    std::cout << "Harmonic Average of List B (empty): " << b.getHarmonicAverage() << std::endl;
    std::cout << "Harmonic Average of List C (1, 0): " << c.getHarmonicAverage() << std::endl;
    return 0;
}
```
- **Expected Output**
```console
Harmonic Average of List A (2, 4, 8): 3.4286
Harmonic Average of List B (empty): 0.0000
Harmonic Average of List C (1, 0): 0.0000
```
