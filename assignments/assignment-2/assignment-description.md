# CENG301, Fall 2025 (My Grade: 100%)

## Homework Assignment II

> [!IMPORTANT]
> Due: **23.59, Dec. 7th, 2025**

## Description

Mordecai and Rigby are working in the Park, but their boss Benson is tired of
their slacking. To keep them busy, Benson wants them to collect some statistics
and perform complex operations on the trees in the Park. In this homework, you
will implement **Binary Tree** structure to represent the trees in the Park.
Each node in the tree has a specific `value` (or `weight`).

## Functional Requirements

Implement the following member functions for the `BinaryTree` class.

> [!IMPORTANT]
> The [Functional Requirements](#functional-requirements) section doesn't
> actually include it, but you also have to implement the constructor yourself.

1. **`double getSubTreeWeight(int id)` (10 points):** Finds the node with the
given `id` and calculates the weight of all nodes in the subtree rooted at that
node (including the node itself). If the node `id` doesn't exist, return `0.0`.

2. **`void enumerateBFS()` (10 points):** Performs a Breadth-First Search (BFS)
of the entire tree, starting from the root. **Prints** the `id`s of the nodes in
the order they were visited, separated by a single space. Prints a newline
character at the end. If the tree is empty, prints nothing.

3. **`Node* getNodeById(int id)` (5 points):** Searches the entire tree for a
node with the specified `id`. Returns the pointer to the `node` if found,
otherwise returns `nullptr`.

4. **`Node* getLevelById(int id)` (5 points):** Finds the level of the node with
the given `id`. The root node is at level 0. If the `id` doesn't exist, return
-1.

5. **`int getLeftmostRightmostDistance()` (10 points):** Finds the `leftmost`
and `rightmost` nodes of the tree. The leftmost node is found by always
traversing to the `left` child from the root. The rightmost node is found by
always traversing to the `right` child from the root. The function then returns
the **sum of their levels**. (e.g. if leftmost is at level 2 and rightmost is
at level 3, return 5). If the tree is empty, return 0.

6. **`int getFarthestLeafId()` (10 points):** Finds the leaf node that is at the
greatest depth (most distant from the root). Returns the `id` of this leaf node.
If there are ties (multiple leaves at the same max depth), return the
**leftmost** one.

7. **`int getClosestLeafId()` (10 points):** Finds the leaf node that is at the
shallowest depth (closest to the root). Returns the `id` of this leaf node. If
the root is also a leaf, return the root's `id`. If there are ties, return the
**leftmost** one.

8. **`void changeRoot(intt newRootId)` (15 points):** Sets the node with
`newRootId` as the new root of the tree. **This operation fails and does nothing
if the target node already has two children (left and right are both
non-null)**. If successful, the `newRoot` is detached from its original parent.
The `oldRoot` (and its entire subtree) becomes the **left child** of the
`newRoot` (if its left slot is empty). If the left slot is full, the `oldRoot`
becomes the **right child** (assuming the right slot is empty).

9. **`void addNode(Node* parent, int value, bool isLeft)` (10 points):** Creates
a new `Node` with the given `value` and a new unique `id` (which must be
`greatestId + 1`). This new node is added as the **left child** of the `parent`
if `isLeft` is true, or the **right child** if `isLeft` is false. **If the
target child slot (left or right) is already occupied, the function does
nothing.** If `parent` is `nullptr` and the tree root is `nullptr`, this new
node becomes the root. After adding, `greatestIDEver` must be incremented.

10. **`void removeNode(int id)` (10 points):** Finds the node with the given
`id` and removes it. **This function only supports removing the nodes with 0 or
1 child.** If a node has 1 child, that child takes its place. **If the target
node to be removed has 2 children, the function does nothing.** This function
does not update `greatestIDEver`.

11. **`void printTreeInOrder()` (5 points):** Prints the entire tree using an
**In-Order** traversal (Left, Root, Right). Each node should be printed on a
newline in the exact format: `Node value: [v], Node Id: [id]`

## IMPORTANT NOTES

> [!IMPORTANT]
> **<u>Do not start your homework before reading these notes!!!</u>**

1. You ARE NOT ALLOWED to modify the given header file (`BinaryTree.h`)

2. You ARE NOT ALLOWED to use any global variables. Any *private helper
functions* you need (e.g., recursive helpers) MUST be defined inside the `ifdef`
block of the function that needs them.

3. You are **allowed and encouraged** to call other public member functions
(like `getNodeById`) from within your implementation of another function.

4. Your output for each operation MUST exactly match the format shown in the
example output (e.g., for `printTreeInOrder` and `enumerateBFS`). Otherwise, you
will not receive points for that part.

5. Using the C++ STL (Standard Template Library) is restricted. You are
**ALLOWED** to use `<vector>`, `<queue>`, and `<stack>`. You **STRICTLY
FORBIDDEN** from using other STL containers like `<map>`, `<set>`, `<list>`,
`<unordered_map>`, etc.

## Example Test Cases

<u>**To test your code, you will need to create separate `main.cpp` files.**</u>

- **Building a Tree:** Many examples below use this `Base Tree`. You can build
it in your `main` function.
```cpp
// Helper function to build the base tree for testing
// Note: greatestIDEver starts at 1, so first Node ID is 2.
void buildBaseTree(BinaryTree& tree) {
    tree.addNode(nullptr, 100, true); // ID 2
    tree.addNode(tree.root, 20, true); // ID 3
    tree.addNode(tree.root, 30, false); // ID 4
    tree.addNode(tree.getNodeById(3), 40, true); // ID 5
    tree.addNode(tree.getNodeById(4), 50, true); // ID 6
    tree.addNode(tree.getNodeById(4), 60, false); // ID 7
    tree.addNode(tree.getNodeById(7), 70, true); // ID 8
}
/* Base Tree Structure: (IDs are 2-8)
     2(100)
    /     \
  3(20)   4(30)
  /      /     \
5(40)  6(50)   7(60)
               /
             8(70)
*/
```

### Function Examples

1. **Constructor**

- **Input Code (`main.cpp`):**
```cpp
#include "BinaryTree.h"
#include <iostream>
int main() {
    BinaryTree tree;
    std::cout << "Root: " << (tree.root == nullptr ? "null" : "not null") << std::endl;
    std::cout << "Greatest ID: " << tree.greatestIDEver << std::endl;
    return 0;
}
```
- **Expected Output:**
```console
Root: null
Greatest ID: 1
```

2. **`addNode`**

- **Input Code (`main.cpp`):**
```cpp
#include "BinaryTree.h"
#include <iostream>
int main() {
    BinaryTree tree;
    tree.addNode(nullptr, 10, true); // ID 2
    tree.addNode(tree.root, 20, true); // ID 3
    tree.addNode(tree.root, 30, false); // ID 4
    tree.addNode(tree.root->left, 25, false); // ID 5

    std::cout << "Root: " << tree.root->value << std::endl;
    std::cout << "Root L: " << tree.root->left->value << std::endl;
    std::cout << "Root R: " << tree.root->right->value << std::endl;
    std::cout << "Root L R: " << tree.root->left->right->value << std::endl;
    return 0;
}
```
- **Expected Output:**
```console
Root: 10
Root L: 20
Root R: 30
Root L R: 25
```

3. **`getSubTreeWeight`**

- **Input Code (`main.cpp`):**
```cpp
#include "BinaryTree.h"
#include <iostream>
int main() {
// Include buildBaseTree function here
int main() {
    BinaryTree tree;
    buildBaseTree(tree);
    // Subtree 4: (30 + 50 + 60 + 70) / 4 = 210 / 4 = 52.5
    std::cout << std::fixed << std::setprecision(2);
    std::cout << "Subtree 4 weight: " << tree.getSubtreeWeight(4) << std::endl;
    // Subtree 3: (20 + 40) / 2 = 60 / 2 = 30.0
    std::cout << "Subtree 3 weight: " << tree.getSubtreeWeight(3) << std::endl;
    return 0;
}
```
- **Expected Output:**
```console
Subtree 4 weight: 52.50
Subtree 3 weight: 30.00
```

4. **`enumerateBFS`**

- **Input Code (`main.cpp`):**
```cpp
#include "BinaryTree.h"
#include <iostream>
int main() {
// Include buildBaseTree function here
int main() {
    BinaryTree tree;
    buildBaseTree(tree);
    tree.enumerateBFS();
    return 0;
}
```
- **Expected Output:**
```console
2 3 4 5 6 7 8
```

5. **`getLevelById`**

- **Input Code (`main.cpp`):**
```cpp
#include "BinaryTree.h"
#include <iostream>
int main() {
// Include buildBaseTree function here
int main() {
    BinaryTree tree;
    buildBaseTree(tree);
    std::cout << "Level 2: " << tree.getLevelById(2) << std::endl;
    std::cout << "Level 6: " << tree.getLevelById(6) << std::endl;
    std::cout << "Level 8: " << tree.getLevelById(8) << std::endl;
    std::cout << "Level 99: " << tree.getLevelById(99) << std::endl;
    return 0;
}
```
- **Expected Output:**
```console
Level 2: 0
Level 6: 2
Level 8: 3
Level 99: -1
```

6. **`getLeftmostRightmostDistance`**

- **Input Code (`main.cpp`):**
```cpp
#include "BinaryTree.h"
#include <iostream>
int main() {
// Include buildBaseTree function here
int main() {
    BinaryTree tree;
    buildBaseTree(tree);
    // Leftmost: 5 (level 2), Rightmost: 7 (level 2)
    // Sum = 2 + 2 = 4
    std::cout << "Dist: " << tree.getLeftmostRightmostDistance() << std::endl;
    return 0;
}
```
- **Expected Output:**
```console
Dist: 4
```

7. **`getFarthestLeafId / getClosestLeafId`**

- **Input Code (`main.cpp`):**
```cpp
#include "BinaryTree.h"
#include <iostream>
int main() {
// Include buildBaseTree function here
int main() {
    BinaryTree tree;
    buildBaseTree(tree);
    // Leaves: 5 (depth 2), 6 (depth 2), 8 (depth 3)
    // Farthest: 8
    // Closest: 5 (5 is leftmost of {5, 6})
    std::cout << "Farthest: " << tree.getFarthestLeafId() << std::endl;
    std::cout << "Closest: " << tree.getClosestLeafId() << std::endl;
    return 0;
}
```
- **Expected Output:**
```console
Farthest: 8
Closest: 5
```

8. **`removeNode`**

- **Input Code (`main.cpp`):**
```cpp
#include "BinaryTree.h"
#include <iostream>
int main() {
// Include buildBaseTree function here
int main() {
    BinaryTree tree;
    buildBaseTree(tree);
    Node* node4 = tree.getNodeById(4);

    std::cout << "Node 4 Left (Before): " << (node4->left ? node4->left->id : 0) << std::endl;
    tree.removeNode(6); // Remove leaf (ID 6)
    std::cout << "Node 4 Left (After): " << (node4->left ? node4->left->id : 0) << std::endl;

    std::cout << "Root Left (Before): " << tree.root->left->id << std::endl;
    tree.removeNode(3); // Remove node 3, promote 5
    std::cout << "Root Left (After): " << tree.root->left->id << std::endl;
    return 0;
}
```
- **Expected Output:**
```console
Node 4 Left (Before): 6
Node 4 Left (After): 0
Root Left (Before): 3
Root Left (After): 5
```

9. **`changeRoot`**

- **Input Code (`main.cpp`):**
```cpp
#include "BinaryTree.h"
#include <iostream>
int main() {
// Include buildBaseTree function here
int main() {
    BinaryTree tree;
    buildBaseTree(tree);

    // Success, Node 7 has 1 child (8)

    tree.changeRoot(7);
    tree.printTreeInOrder();

    return 0;
}
```
- **Expected Output:**
```console
Node value: 70, Node Id: 8
Node value: 60, Node Id: 7
Node value: 40, Node Id: 5
Node value: 20, Node Id: 3
Node value: 100, Node Id: 2
Node value: 50, Node Id: 6
Node value: 30, Node Id: 4
```

10. **`printTreeInOrder`**

- **Input Code (`main.cpp`):**
```cpp
#include "BinaryTree.h"
#include <iostream>
int main() {
// Include buildBaseTree function here
int main() {
    BinaryTree tree;
    buildBaseTree(tree);
    std::cout << "--- In-Order Traversal ---" << std::endl;
    tree.printTreeInOrder();
    return 0;
}
```
- **Expected Output:**
```console
--- In-Order Traversal ---
Node value: 40, Node Id: 5
Node value: 20, Node Id: 3
Node value: 100, Node Id: 2
Node value: 50, Node Id: 6
Node value: 30, Node Id: 4
Node value: 70, Node Id: 8
Node value: 60, Node Id: 7
```

