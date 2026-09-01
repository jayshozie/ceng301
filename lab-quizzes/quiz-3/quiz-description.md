# Hash Table (My Grade: 100%)

In this lab quiz, you are asked to implement a simplified `HashTable` using
**Linear Probing**. The following helper functions are already implemented and
provisioned to you in the background:
- `isPrime(int n)` and `getNextPrime(int n)`
- `printTable()` (prints the current state of the table)
- `search()` and `remove()` (standard linear probing logic)

You are required to implement ONLY the following 3 functions in `HashTable.cpp`:
1. `performHash`: Calculate the hash value
2. `insert`: Insert a key-value pair using Linear Probing (assuming sufficient
space)
3. `resizeTable`: Handle the dynamic resizing of the table

These vector functions could be helpful, especially in the last question:
- `push_back(val)`: Adds one element to the end
- `resize(n)`: Changes the total size to `n` (adding default zeroes or deleting
elements)

## Quick Example

```cpp
std::vector<int> v;
v.push_back(5);
// v: {5} (Size: 1)
v.resize(3);
// v: {5, 0, 0} (Size: 3)
v.resize(1);
// v: {5} (Size: 1)
```

## *Task 1: Hash Function Implementation*

Implement the primary hash function using the polynomial rolling hash formula:
```latex
$
H(k) = (\sum_{i=0}^{L-1}{K[i] \times 33^{i}}) mod M
$
```
Where $`M`$ is `sizeTable`.

- **Test Case 1:**
```cpp
#include "HashTable.h"
#include <iostream>

int main()
{
    // Case 1: Simple Character:
    // 'A' is 65. Table Size 100. Hash = 65 % 100 = 65.
    HashTable ht1(100);
    std::cout << "Test 1 (A): " << ht1.performHash("A") << std::endl;

    return 0;
}
```
- **Expected Output**
```console
Test 1 (A): 65
```

- **Test Case 2:**
```cpp
#include "HashTable.h"
#include <iostream>

int main()
{

    // Case 2: String Concatenation Logic
    // 'A'(65) + 'B'(66)*33 = 65 + 2178 = 2243. 
    // Table Size 100. Hash = 2243 % 100 = 43.
    HashTable ht2(100);
    std::cout << "Test 2 (AB): " << ht2.performHash("AB") << std::endl;

    return 0;
}
```
- **Expected Output**
```console
Test 2 (AB): 43
```

- **Test Case 3:**
```cpp
#include "HashTable.h"
#include <iostream>

int main()
{
    // Case 3: Small Table Size (Modulo Effect)
    // 'A'(65). Table Size 10. Hash = 65 % 10 = 5.
    HashTable ht3(10);
    std::cout << "Test 3 (A mod 10): " << ht3.performHash("A") << std::endl;

    return 0;
}
```
- **Expected Output**
```console
Test 3 (A mod 10): 5
```

---

## *Task 2: Insertion (Linear Probing)*

Implement the insert function.

- Calculate the starting index using `performHash`.
- If the slot is `EMPTY` or `DELETED`, insert the new entry.
- If the slot is `OCCUPIED` by a different key, move to the next slot:
    - `Idxnext = (CurrentIdx + 1) (mod M)`.
- If the key already exists, update its value.
> [!NOTE]
> Do not call `resizeTable` inside this function for this task (assume capacity is
> sufficient for these specific tests).

- **Test Case:**
```cpp
#include "HashTable.h"
#include <iostream>

int main()
{
    HashTable ht(7); // Size 7

    // Case 1: No Collision Insertion
    // 'A' (65) % 7 = 2.
    ht.insert("A", 10); 
    
    // Case 2: Linear Collision
    // 'H' (72) % 7 = 2. Collision with 'A' at index 2 -> Probe to 3.
    ht.insert("H", 20);

    // Case 3: Wrap Around Collision
    // 'F' (70) % 7 = 0.
    // 'M' (77) % 7 = 0. Collision -> Probe to 1.
    // 'T' (84) % 7 = 0. Collision -> Probe 0->1(Busy)->2(Busy)->3(Busy)->4.
    // Wait, let's verify positions:
    // 0: F
    // 2: A
    // 3: H (Because H wanted 2, found A, went to 3)
    // Now inserting M (want 0): 0 is F. Next is 1. 1 is Empty. M goes to 1.
    ht.insert("F", 30);
    ht.insert("M", 40);

    ht.printTable();
    return 0;
}
```
- **Expected Output**
```console
Size: 7
0: F (30)
1: M (40)
2: A (10)
3: H (20)
```

---

## *Task 2: Resizing (Rehashing)*

Implement `resizeTable()`. 

- **Logic:**
    1. Calculate the `newSize`: The smallest prime number $`\geq 2 * \text{oldSize}`$.
    2. Create a new table.
    3. Reinsert all `OCCUPIED` entries from the old table into the new table
    (recalculate hash indices based on `newSize`).
    4. `DELETED` entries should be discarded.

- **Test Case 1:**
```cpp
#include "HashTable.h"
#include <iostream>

int main()
{
    // Initial Size 5. 
    HashTable ht(5); 

    // Case 1: Fill up
    ht.insert("A", 1); 
    ht.insert("B", 2); 
    
    std::cout << "--- Before Resize ---" << std::endl;
    ht.printTable();

    // Case 2: Manual Resize Trigger
    // We explicitly call resizeTable to test it.
    // Old Size 5 -> New Size: NextPrime(5 * 2) = 11.
    ht.resizeTable();

    std::cout << "--- After Resize ---" << std::endl;
    std::cout << "New Table Size: " << ht.tableSize << std::endl;
    ht.printTable();

    // Case 3: Insert into new table
    // In size 11: 'C'(67) % 11 = 1
    ht.insert("C", 3);
    
    std::cout << "--- After New Insertion ---" << std::endl;
    ht.printTable();
    
    return 0;
}
```
- **Expected Output**
```console
--- Before Resize ---
Size: 5
0: A (1)
1: B (2)
--- After Resize ---
New Table Size: 11
0: B (2)
1: C (3)
10: A (1)
```

