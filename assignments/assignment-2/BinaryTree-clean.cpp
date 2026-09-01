#include "BinaryTree.h"
#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <cmath>
#include <iomanip>
#include <climits>

/*
 * Cleaned from if macro blocks for syntax highlighting in neovim.
 */

// Note: Do not use 'using namespace std;' in your .cpp file.
// Use std:: directly (e.g., std::cout, std::vector).

/**
 * Constructor: Initializes an empty tree.
 * root should be nullptr.
 * greatestIDEver should be 1.
 */
BinaryTree::BinaryTree() // constructed correctly according to the manual
    : root(nullptr), greatestIDEver(1) {} // default constructor

/**
 * Destructor: Frees all dynamically allocated memory.
 * (Hint: Define a recursive helper function *inside* this #ifdef block)
 */
void BinaryTree::destroy(Node* node)
{
    if(node == nullptr) { return; }
    destroy(node->left);
    destroy(node->right);
    delete node;
} // destructor recursive helper
BinaryTree::~BinaryTree()
{
    destroy(this->root); // only the root node is left
    this->root = nullptr; // completely destroyed
} // destructor

/**
 * Calculates the average weight of the subtree rooted at node `id`.
 * (Hint: You can call this->getNodeById(id) to get the node.)
 */
void BinaryTree::getSubtreeWeight(Node* node, long long int& sum, int& count)
{
    if(node == nullptr) { // base case 1: null link, contributes 0 to both
        sum = 0;
        count = 0;
        return;
    }
    // initialize temp results for children
    long long int leftSum = 0;
    int leftCount = 0;
    long long int rightSum = 0;
    int rightCount = 0;

    // recurse lhs and rhs
    getSubtreeWeight(node->left, leftSum, leftCount);
    getSubtreeWeight(node->right, rightSum, rightCount);

    sum = leftSum + rightSum + node->value;
    count = leftCount + rightCount + 1;
} // get subtree weight recursive helper
double BinaryTree::getSubtreeWeight(int id)
{
    Node* start = this->getNodeById(id);
    if(start == nullptr) { return 0.0; }

    long long sum = 0;
    int count = 0;

    getSubtreeWeight(start, sum, count);

    return (count == 0) ? 0.0 : ((double)sum / (double)count);
} // get subtree weight

/**
 * Enumerates the node IDs in BFS order, printing them.
 * Output format: "id1 id2 id3 \n"
 */
void BinaryTree::enumerateBFS(Node* start)
{
    if(start == nullptr) {
        return;
        // if start node is nullptr, then we're done with that leaf
    }
    std::queue<Node*> q; // regular queue from std
    std::vector<int> ids;

    q.push(start); // using a queue to keep track of the nodes
    while(!q.empty()) { // if queue is not empty
        Node* curr = q.front(); // q.peek();
        q.pop(); // q.dequeue();

        ids.push_back(curr->id); // keeping track of the ids
        if(curr->left != nullptr) { q.push(curr->left); } // recursion
        if(curr->right != nullptr) { q.push(curr->right); } // recursion
    }
    if(ids.empty()) {
        return;
        // if ids is empty, done with enumeration
    }
    for(int i = 0; i < (int)(ids.size()); i++) {
        std::cout << ids[i] << " ";
    } // cout all ids in the ids stack
    std::cout << std::endl;
}
void BinaryTree::enumerateBFS()
{
    this->enumerateBFS(this->root);
} // enum

/**
 * Finds and returns a pointer to the node with the given `id`.
 * (Hint: Define a recursive helper function *inside* this #ifdef block)
 */
Node* BinaryTree::getNodeById(Node* node, int id)
{
    if(node == nullptr) { return nullptr; }
    if(node->id == id) { return node; }

    Node* leftRes = getNodeById(node->left, id);
    if(leftRes != nullptr) { return leftRes; }

    return getNodeById(node->right, id);
}
Node* BinaryTree::getNodeById(int id)
{
    return getNodeById(this->root, id);
} // get node

/**
 * Finds the level of the node with the given `id`. Root is level 0.
 * (Hint: A BFS is a good way to find level)
 */
int BinaryTree::getLevelById(Node* node, int id, int currentLevel)
{
    if(node == nullptr) { return -1; }
    if(node->id == id) { return currentLevel; }

    int left = getLevelById(node->left, id, currentLevel + 1);
    if(left != -1) { return left; }

    return getLevelById(node->right, id, currentLevel + 1);
}
int BinaryTree::getLevelById(int id)
{
    if(this->root == nullptr) { return -1; }
    return getLevelById(this->root, id, 0);
} // get level

/**
 * Finds the distance between the leftmost and rightmost nodes.
 * (Hint: You can call this->getLevelById(id) on the nodes.)
 */
Node* BinaryTree::getLeftmost(Node* node)
{
    if(node == nullptr) { return nullptr; }
    Node* curr = node;
    while(curr->left != nullptr) { curr = curr->left; }
    return curr;
}
Node* BinaryTree::getRightmost(Node* node)
{
    if(node == nullptr) { return nullptr; }
    Node* curr = node;
    while(curr->right != nullptr) { curr = curr->right; }
    return curr;
}
int BinaryTree::getLeftmostRightmostDistance()
{
    if(this->root == nullptr) { return 0; }

    Node* leftmost = getLeftmost(this->root);
    Node* rightmost = getRightmost(this->root);

    if(leftmost == nullptr || rightmost == nullptr) { return 0; }

    int llevel = this->getLevelById(leftmost->id);
    int rlevel = this->getLevelById(rightmost->id);

    if(llevel < 0 || rlevel < 0) { return 0; }

    return llevel + rlevel;
} // get leftmost rightmost distance

/**
 * Finds the ID of the *leftmost* leaf node farthest from the root.
 * (Hint: Define a recursive helper function *inside* this #ifdef block)
 */
void BinaryTree::getFarthestLeafId(Node* node, int depth, int& bestDepth,
                                   int& bestId)
{
    if(node == nullptr) { return; }
    if(node->left == nullptr && node->right == nullptr) {
        if(depth > bestDepth) {
            bestDepth = depth;
            bestId = node->id;
        }
        return;
    }
    if(node->left != nullptr) {
        getFarthestLeafId(node->left, depth + 1, bestDepth, bestId);
    }
    if(node->right != nullptr) {
        getFarthestLeafId(node->right, depth + 1, bestDepth, bestId);
    }
}
int BinaryTree::getFarthestLeafId()
{
    if(this->root == nullptr) { return 0; }

    int bestDepth = -1;
    int bestId = 0;

    getFarthestLeafId(this->root, 0, bestDepth, bestId);
    return bestId;
} // get farthest

/**
 * Finds the ID of the *leftmost* leaf node closest to the root.
 * (Hint: Define a recursive helper function *inside* this #ifdef block)
 */
void BinaryTree::getClosestLeafId(Node* node, int depth, int& bestDepth,
                                  int& bestId)
{
    if(node == nullptr) { return; }
    if(node->left == nullptr && node->right == nullptr) {
        if(bestDepth == -1 || depth < bestDepth) {
            bestDepth = depth;
            bestId = node->id;
        }
        return;
    }
    if(node->left != nullptr) {
        getClosestLeafId(node->left, depth + 1, bestDepth, bestId);
    }
    if(node->right != nullptr) {
        getClosestLeafId(node->right, depth + 1, bestDepth, bestId);
    }
}
int BinaryTree::getClosestLeafId()
{
    if(this->root == nullptr) { return 0; }

    int bestDepth = -1;
    int bestId = 0;

    getClosestLeafId(this->root, 0, bestDepth, bestId);

    return bestId;
} // get closest

/**
 * Changes the root of the tree to the node with `newRootId`.
 * Fails if the new root has 2 children.
 * (Hint: You can call this->getNodeById(id) to get the node.)
 */
Node* BinaryTree::changeRoot(Node* curr, Node* target)
{
    // i'd named this findParent, because that's what it does, but it doesnt't
    // compile with that for some reason
    // base case 1:
    // if curr or target are nullptr, no parent, returned
    if(curr == nullptr || target == nullptr) { return nullptr; }

    // base case 2:
    // if curr's left node is the target or curr's right node is
    // the target, then return curr, because it is the parent of the target node
    if(curr->left == target || curr->right == target) { return curr; }

    // we check the left leaf of the curr to find the target
    Node* leftRes = changeRoot(curr->left, target);

    // if the above line returns anything other than a nullptr, we've found the
    // correct leaf. thus the correct parent.
    if(leftRes != nullptr) { return leftRes; }

    // last case scenario, it's on the right leaf of the curr
    return changeRoot(curr->right, target);
}
void BinaryTree::changeRoot(int newRootId)
{
    // base case 1: tree is empty
    if(this->root == nullptr) { return; } // base tree: skipped

    Node* newRoot = this->getNodeById(newRootId); // newRoot ID: 7 Value: 60
    // we need to keep track of the oldRoot
    Node* oldRoot = this->root; // base tree: oldRoot: ID 2
    // base case 2: the given newRoot either doesn't exist, or is the root
    // itself
    if(newRoot == nullptr || newRoot == oldRoot) {
        return;
        // base tree: skipped
    }

    // base case 3: the newRoot's left AND the right is full
    if(newRoot->left != nullptr && newRoot->right != nullptr) {
        return;
        // base tree: skipped, only left of the node ID: 7 full
    }

    // we need to keep track of the parent of the newRoot
    Node* parent = changeRoot(oldRoot, newRoot); // ID: 4 in base tree

    // -- Detachment Logic ---
    if(parent == nullptr) { // base case 4: parent is nullptr, tree is deformed
        return;
    }
    else {
        if(parent->left == newRoot) { parent->left = nullptr; }
        else if(parent->right == newRoot) {
            parent->right = nullptr;
        }
    }

    // --- Attachment Logic ---
    if(newRoot->left == nullptr) {
        newRoot->left = oldRoot;
        // base tree: ID 7->LEFT == ID 2
    }
    // if the right node is nullptr, we make that point to the old root
    else { // we're sure the right leaf of newRoot is empty at this point
        newRoot->right = oldRoot;
    }

    // we assign the root of the tree to the newRoot
    this->root = newRoot;
} // change root

/**
 * Adds a new node with `value` as a child of `parent`.
 * New node's ID should be greatestIDEver + 1.
 * Don't forget to increment greatestIDEver.
 */
void BinaryTree::addNode(Node* parent, int value, bool isLeft)
{
    if(this->root == nullptr) {
        this->root = new Node(++this->greatestIDEver, value);
        return;
    }
    if(isLeft && parent->left == nullptr) {
        parent->left = new Node(++this->greatestIDEver, value);
    }
    else if(!isLeft && parent->right == nullptr) {
        parent->right = new Node(++this->greatestIDEver, value);
    }
} // add node

/**
 * Removes the node with `id` from the tree.
 * Only works if the node has 0 or 1 child.
 * (Hint: You can call this->getNodeById(id) to get the node.)
 */
bool BinaryTree::removeNode(Node* curr, Node* parent, int id)
{
    if(curr == nullptr) { return false; }
    if(curr->id == id) {
        if(curr->left != nullptr && curr->right != nullptr) { return false; }
        Node* child = (curr->left != nullptr ? curr->left : curr->right);
        if(parent == nullptr) {
            if(child != nullptr) {
                delete curr;
                this->root = nullptr;
            }
            else {
                this->root = child;
                delete curr;
            }
        }
        else {
            if(parent->left == curr) { parent->left = child; }
            else if(parent->right == curr) {
                parent->right = child;
            }
            delete curr;
        }
        return true;
    }
    if(removeNode(curr->left, curr, id)) { return true; }
    if(removeNode(curr->right, curr, id)) { return true; }
    return false;
}
void BinaryTree::removeNode(int id)
{
    removeNode(this->root, nullptr, id);
} // remove node

/**
 * Prints the tree in In-Order (LNR)
 * Format: "Node value: [v], Node Id: [id]\n"
 * (Hint: Define a recursive helper function *inside* this #ifdef block)
 */
void BinaryTree::printTreeInOrder(Node* node)
{
    if(node == nullptr) { return; }
    printTreeInOrder(node->left);
    std::cout << "Node value: " << node->value << ", Node Id: " << node->id
              << std::endl;
    printTreeInOrder(node->right);
}
void BinaryTree::printTreeInOrder()
{
    printTreeInOrder(this->root);
} // print tree in-order
