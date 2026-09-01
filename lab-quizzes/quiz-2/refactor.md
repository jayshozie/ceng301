CENG 301 - Binary Trees Lab Quiz

Fall 2025
Quiz Questions
1. (BinaryTree) Implement Post-Order Traversal (40 points)

Implement the printTreePostOrder member function for the BinaryTree class.

void printTreePostOrder();

Description: Post-Order traversal is a depth-first traversal method where the nodes are visited in the following order:

    Recursively traverse the current node's Left subtree.

    Recursively traverse the current node's Right subtree.

    Visit (print) the Root (current) node.

This means the root of the tree is always the last node to be printed.

Output Format: Each node must be printed on a new line: Node value: [v], Node Id: [id]

Example Test Case 1 (Simple Balanced Tree):

int main() {
    BinaryTree t;
    // Perfect Tree Depth 1 (3 Nodes)
    // Preorder: 1, 2, 3
    //        1
    //      /   \
    //     2     3
    int arr[] = {1, 2, 3};
    t.buildPerfectTree(arr, 3);
    
    std::cout << "Reconstructed (Post-Order Check):" << std::endl;
    t.printTreePostOrder();
    return 0;
}

Expected Output 1:

Node value: 20, Node Id: 3
Node value: 80, Node Id: 4
Node value: 50, Node Id: 2

Example Test Case 2 (Left Skewed Tree):

int main() {
    BinaryTree t;
    // Constructing: 10 -> 20 -> 30 (All Left children)
    t.addNode(nullptr, 10, true);           // Root
    t.addNode(t.root, 20, true);            // Left
    t.addNode(t.getNodeById(3), 30, true); // Left->Left
    
    t.printTreePostOrder();
    return 0;
}

Expected Output 2:

Node value: 30, Node Id: 4
Node value: 20, Node Id: 3
Node value: 10, Node Id: 2

Example Test Case 3 (Complex Tree):

int main() {
    BinaryTree t;
    //       100
    //      /   \
    //    50     150
    //   /
    // 25
    t.addNode(nullptr, 100, true);       // ID 2
    t.addNode(t.root, 50, true);         // ID 3
    t.addNode(t.root, 150, false);       // ID 4
    t.addNode(t.getNodeById(3), 25, true); // ID 5
    
    t.printTreePostOrder();
    return 0;
}

Expected Output 3:

Node value: 25, Node Id: 5
Node value: 50, Node Id: 3
Node value: 150, Node Id: 4
Node value: 100, Node Id: 2

2. (BinaryTree) Implement Remove Node (30 points)

Implement the removeNode function.

void removeNode(int id);

Detailed Description: This function removes a node specified by its unique id. To simplify the logic for this Lab Quiz, we are only handling cases where the removal does not require complex restructuring (like finding a predecessor/successor).

Rules:

    Leaf Node (0 Children): Just delete the node and update its parent's pointer to NULL.

    Single Child (1 Child): Delete the node. Its only child moves up to occupy the deleted node's position (connect grandparent to grandchild).

    Two Children: Do Nothing. For this specific quiz, if a node has both left and right children, ignore the removal request.

Example Test Case 1 (Leaf Removal):

int main() {
    BinaryTree t;
    t.addNode(nullptr, 10, true);       // Root
    t.addNode(t.root, 5, true);         // Left (Leaf)
    
    t.removeNode(3); // Remove ID 3 (Value 5)
    t.printTreePostOrder(); // Should only print Root
    return 0;
}

Expected Output 1:

Node value: 10, Node Id: 2

Example Test Case 2 (1 Child):

int main() {
    BinaryTree t;
    // 10 (Root) -> 20 (Left) -> 30 (Left)
    t.addNode(nullptr, 10, true); 
    t.addNode(t.root, 20, true);  
    t.addNode(t.getNodeById(3), 30, true); 
    
    // Removing 20 (ID 3). 30 should connect to 10.
    t.removeNode(3); 
    
    t.printTreePostOrder();
    return 0;
}

Expected Output 2:

Node value: 30, Node Id: 4
Node value: 10, Node Id: 2

Example Input 3 (2 Children Case - Do Nothing):

int main() 

{
    BinaryTree t;

    // Tree:
    //      50 (ID: 2)
    //     /   \
    //   20     80
    // (ID:3) (ID:4)

    t.addNode(nullptr, 50, true);   // Root
    t.addNode(t.root, 20, true);    // Left Child
    t.addNode(t.root, 80, false);   // Right Child

    std::cout << "Before Removal (Post-Order):" << std::endl;
    t.printTreePostOrder();

    // Trying to remove: ID 2 (root) 
    // Recall the rule: If the node to be removed has 2 children, do nothing!
    t.removeNode(2); 

    std::cout << "\nAfter Attempting Removal of ID 2 (Should be same):" << std::endl;
    t.printTreePostOrder();
    
    return 0;
}


Expected Output 3:

--- Test: Remove Node with 2 Children ---
Before Removal (Post-Order):
Node value: 20, Node Id: 3
Node value: 80, Node Id: 4
Node value: 50, Node Id: 2

After Attempting Removal of ID 2 (Should be same):
Node value: 20, Node Id: 3
Node value: 80, Node Id: 4
Node value: 50, Node Id: 2

3. (BinaryTree) Build Perfect Tree from Array (30 points)

Implement the function to reconstruct a tree from a Preorder array.

void buildPerfectTree(int* values, int size);

What is a Perfect Binary Tree? A Perfect Binary Tree is a special type of binary tree in which all interior nodes have exactly two children and all leaf nodes are at the same level (depth).

    All levels are completely filled.

    The total number of nodes N in a perfect binary tree of depth d is N= (2^(d+1))−1.

Task Description: You are given an integer array representing the Preorder Traversal (Root → Left → Right) of a Perfect Binary Tree. You must reconstruct the tree structure using the existing addNode helper.

Notes: The input size will always correspond to a valid perfect tree. You can use the given addNode function.

Example Test Case 1:

int main() {
    BinaryTree t;
    // Perfect Tree Depth 1 (3 Nodes)
    // Preorder: 1, 2, 3
    //       1
    //     /   \
    //    2     3
    int arr[] = {1, 2, 3};
    t.buildPerfectTree(arr, 3);
    
    std::cout << "Reconstructed (Post-Order Check):" << std::endl;
    t.printTreePostOrder();
    return 0;
}

Example Output 1:

Reconstructed (Post-Order Check):
Node value: 2, Node Id: 3
Node value: 3, Node Id: 4
Node value: 1, Node Id: 2

Example Test Case 2:

int main() {
    BinaryTree t;

    int values[] = {1, 2, 3, 4, 5, 6, 7};
    int size = 7;

    t.buildPerfectTree(values, size);

    t.printTreePostOrder();
    
    return 0;
}

Expected Output 2:

Node value: 3, Node Id: 4
Node value: 4, Node Id: 5
Node value: 2, Node Id: 3
Node value: 6, Node Id: 7
Node value: 7, Node Id: 8
Node value: 5, Node Id: 6
Node value: 1, Node Id: 2

Example Test Case 3:

int main() {
    BinaryTree t;

    int values[] = {100, 50, 25, 75, 150, 125, 175};
    int size = 7;

    t.buildPerfectTree(values, size);

    t.printTreePostOrder();
    
    return 0;
}

Expected Output 3:


Node value: 25, Node Id: 4
Node value: 75, Node Id: 5
Node value: 50, Node Id: 3
Node value: 125, Node Id: 7
Node value: 175, Node Id: 8
Node value: 150, Node Id: 6
Node value: 100, Node Id: 2
