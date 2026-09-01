# CENG301, Fall 2025 (My Grade: 100%)

## Homework Assignment III

> [!IMPORTANT]
> Due: **23.59, Dec. 26th, 2025**

## Description

Globex Corporation needs a high-performance **Employee Lookup System**. Your
task is to implement a `HashTable` class that stores employee names (strings)
and their corresponding Employee IDs (integers).

You must implement four collision resolution strategies: three Open Addressing
methods and one Separate Chaining method.

## Grading Rubric

This homework will be graded based on the following breakdown (Total: 100%):

| **Task / Component**                                          | Points |
|:--------------------------------------------------------------|:------:|
| 1. Hash Functions (Primary & Secondary)                       |   10   |
| 2. Helper Functions (Prime checks, etc.)                      |   10   |
| 3. Open Addressing Implementation (Linear, Quadratic, Double) |   35   |
| 4. Separate Chaining Implementation                           |   25   |
| 5. Resizing (Rehashing) Logic                                 |   20   |
| **Total**                                                     |  100   |


## Technical Specifications

1. **Hash Functions (10 points)**

Convert the string key (`K`) into an integer using the following formula:
```latex
$
H(K) = (\sum_{i=0}^{L-1}{K[i]} \times 33^{i}}) mod M
$
```

- Use `unsigned int` for the calculation to allow natural overflow.
- `M` represents table size.
- **Secondary Hash (for Double Hashing):** Implement
```latex
$
H_{2}(K) = (P - ((\sum_{i=0}^{L-1}{K[i} \times 33^{i}}) mod P)) mod M
$
```
Where `P` is the largest prime strictly smaller than `M`.

<!-- Above LaTeX codes are faulty. Needs FIX -->

2. **Collision Strategies**
    You will support the following strategies. Let $`H(K)`$ be the primary
    index.

    1. **Open Addressing Strategies (35 points)**
    
    These store data in a flat table (`std::vector<HashEntry> table`). You must
    implement `insert`, `search`, and `remove` for:
    - **Linear Probing** $`\text{Idx}_i = (H(K) + i) (mod M)`$
    - **Quadratic Probing** $`\text{Idx}_i = (H(K) + i^{2}) (mod M)`$
    - **Double Hashing** $`\text{Idx}_i = (H(K) + i \times H_{2}(K)) (mod M)`$

    > [!NOTE]
    > You must handle "Lazy Deletion" correctly for Open Addressing.

    2. **Separate Chaining Strategy (25 points)**

    This stores data in a bucket array
    (`std::vector<std::vector<HashEntry>> buckets`).

    - Map the key to index $`H(K)`$. That index contains a list (vector) of
    entries.
    - Collisions are resolved by appending the new entry to the end of the
    vector at that index.
    - `remove` should physically delete the entry from the vector (no lazy
    deletion needed here).

3. **Resizing (Rehashing) (20 points)**

    - **Threshold:** Resize when the load factor:
        ```latex
        \lamda = \frac{\text{num_occupied}}{M} > 0.5
        ```
    - **New Size:** The new table size must be the **first prime number**
    greater than or equal to $`2 \times M_{\text{old}}`$.
    - **Process:** Create a new table (or new buckets). Rehash all `OCCUPIED`
    entries. `DELETED` entries are ignored.

4. **Helper Functions (10 points)**
    You must strictly implement `isPrime` and `getNextPrime` manually.
    - **`isPrime(int n)`:** Returns `true` if `n` is prime.
    - **`getNextPrime(int n)`:** Returns the smallest prime number $`\geq n`$.

## IMPORTANT NOTES

> [!IMPORTANT]
> **<u>Do not start your homework before reading these notes!!!</u>**

1. You ARE NOT ALLOWED to modify the given header file (`HashTable.h`)

2. You ARE NOT ALLOWED to use any global variables. Any *private helper
functions* you need (e.g., recursive helpers) MUST be defined inside the `ifdef`
block of the function that needs them or as private members if you were allowed
to modify the header (which you're not, so use static helpers or define them in
`.cpp`).

3. You are **allowed and encouraged** to call other public member functions
(like `performHash` or `isPrime`) from within your implementation of another
function.

4. Your output for each operation MUST exactly match the format shown in the
example output (e.g., for `printTable`). Otherwise, you will not receive points
for that part.

5. Using the C++ STL (Standard Template Library) is restricted. You are
**ALLOWED** to use `<vector>`, `<string>`, and `<iostream>`. You **STRICTLY
FORBIDDEN** from using other STL containers like `<map>`, `<set>`, `<list>`,
`<unordered_map>`, etc.

## Example Test Cases

Use the following `main` functions to test your code. Your output must match the
expected output exactly.

1. **Primary Hash Function Check**

- **Goal:** Verify `performHash` calculates values correctly.
```cpp
// test_hash1.cpp
#include "HashTable.h"
#include <iostream>
int main()
{
    // Size 1000 to see raw hash clearly without too much mod effect
    HashTable ht(LINEAR, 1000);
    std::cout << "Hash(A): " << ht.performHash("A") << std::endl;
    std::cout << "Hash(Ali): " << ht.performHash("Ali") << std::endl;
    return 0;
}
```

- **Expected Output:**
```console
Hash(A): 65
Hash(Ali): 974
```

2. **Secondary Hash Check**

- **Goal:** Verify `performHash2` for Double Hashing.
```cpp
// test_hash2.cpp
#include "HashTable.h"
#include <iostream>
int main()
{
    // TableSize 11 -> P = 7 (Largest prime < 11)
    HashTable ht(DOUBLE, 11);
    std::cout << "H2(A): " << ht.performHash2("A") << std::endl;
    std::cout << "H2(B): " << ht.performHash2("B") << std::endl;
    return 0;
}
```

- **Expected Output:**
```console
H2(A): 5
H2(B): 4
```

3. **Prime Checking**

- **Goal:** Verify `isPrime`.
```cpp
// test_prime_check.cpp
#include "HashTable.h"
#include <iostream>
int main()
{
    HashTable ht(LINEAR, 7);
    std::cout << "7 is prime? " << ht.isPrime(7) << std::endl;
    std::cout << "10 is prime? " << ht.isPrime(10) << std::endl;
    std::cout << "1 is prime? " << ht.isPrime(1) << std::endl;
    std::cout << "13 is prime? " << ht.isPrime(13) << std::endl;
    return 0;
}
```

- **Expected Output:**
```console
7 is prime? 1
10 is prime? 0
1 is prime? 0
13 is prime? 1
```

4. **Next Prime**

- **Goal:** Verify `getNextPrime`.
```cpp
// test_next_prime.cpp
#include "HashTable.h"
#include <iostream>
int main()
{
    HashTable ht(LINEAR, 7);
    std::cout << "Next(14): " << ht.getNextPrime(14) << std::endl;
    std::cout << "Next(17): " << ht.getNextPrime(17) << std::endl;
    std::cout << "Next(20): " << ht.getNextPrime(20) << std::endl;
    return 0;
}
```

- **Expected Output:**
```console
Next(14): 17
Next(17): 17
Next(20): 23
```

5. **Linear Probing (No Resize)**

- **Goal:** Linear collision resolution.
```cpp
// test_linear_probing_no_resize.cpp
#include "HashTable.h"
#include <iostream>
int main()
{
    HashTable ht(LINEAR, 11);
    ht.insert("A", 1); // Hash("A") % 11 = 10
    ht.insert("L", 2); // Hash("L") % 11 = 10 (Collision -> 0)
    ht.insert("W", 3); // Hash("W") % 11 = 10 (Collision -> 0 -> 1)
    ht.printTable();
    return 0;
}
```

- **Expected Output:**
```console
Size: 11
0: L (2)
1: W (3)
10: A (1)
```

6. **Quadratic Probing (No Resize)**

- **Goal:** Quadratic collision resolution.
```cpp
// test_quadratic_probing_no_resize.cpp
#include "HashTable.h"
#include <iostream>
int main()
{
    HashTable ht(QUADRATIC, 11);
    ht.insert("A", 1);
    ht.insert("L", 2); // 10 -> 10+1^2 = 0
    ht.insert("W", 3); // 10 -> 10+1^2=0(Busy) -> 10+2^2=14->3
    ht.printTable();
    return 0;
}
```

- **Expected Output:**
```console
Size: 11
0: L (2)
3: W (3)
10: A (1)
```

7. **Double Hashing (No Resize)**

- **Goal:** Double hashing collision resolution.
```cpp
// test_double_hashing_probing_no_resize.cpp
#include "HashTable.h"
#include <iostream>
int main()
{
    HashTable ht(DOUBLE, 11);
    ht.insert("A", 1);
    ht.insert("L", 2);
    ht.insert("W", 3);
    ht.printTable();
    return 0;
}
```

- **Expected Output:**
```console
Size: 11
0: L (2)
3: W (3)
10: A (1)
```

8. **Deletion and Search (Linear)**

- **Goal:** Verify "Lazy Deletion" and search continuity.
```cpp
// test_linear_probing_deletion_and_search.cpp
#include "HashTable.h"
#include <iostream>
int main()
{
    HashTable ht(LINEAR, 11);
    ht.insert("A", 1);
    ht.insert("L", 2);
    ht.insert("W", 3);
    ht.remove("L"); // Index 0 becomes DELETED
    int val;
    bool foundW = ht.search("W", val);
    bool foundL = ht.search("L", val);
    std::cout << "Search W: " << (foundW ? "Found" : "Not Found") << std::endl;
    std::cout << "Search L: " << (foundL ? "Found" : "Not Found") << std::endl;
    ht.printTable();
    return 0;
}
```

- **Expected Output:**
```console
Search W: Found
Search L: Not Found
Size: 11
0: DELETED
1: W (3)
10: A (1)
```

9. **Separate Chaining**

- **Goal:** Verify bucket lists.
```cpp
// test_separate_chaining.cpp
#include "HashTable.h"
#include <iostream>
int main()
{
    HashTable ht(SEPARATE_CHAINING, 11);
    ht.insert("A", 1);
    ht.insert("L", 2);
    ht.insert("B", 3);
    ht.printTable();
    return 0;
}
```

- **Expected Output:**
```console
Size: 11
0: [B:3] -> NULL
10: [A:1] -> [L:2] -> NULL
```

10. **Linear Probing Resize**

- **Goal:** Verify resizing logic.
```cpp
// test_separate_chaining.cpp
#include "HashTable.h"
#include <iostream>
int main()
{
    HashTable ht(LINEAR, 5);
    ht.insert("A", 1);
    ht.insert("B", 2);
    std::cout << "--- Before Resize ---" << std::endl;
    ht.printTable();
    ht.insert("C", 3); // Load > 0.5 -> Resize to 11
    std::cout << "--- After Resize ---" << std::endl;
    ht.printTable();
    return 0;
}
```

- **Expected Output:**
```console
--- Before Resize ---
Size: 5
0: A (1)
1: B (2)
--- After Resize ---
Size: 11
0: B (2)
1: C (3)
10: A (1)
```
