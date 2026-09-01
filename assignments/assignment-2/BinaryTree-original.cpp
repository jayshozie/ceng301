#include "BinaryTree.h"
#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <cmath>
#include <iomanip> // For printing doubles
#include <climits> // For INT_MAX/INT_MIN

// Note: Do not use 'using namespace std;' in your .cpp file.
// Use std:: directly (e.g., std::cout, std::vector).

#ifdef USE_STUDENT_CONSTRUCTOR_IMPL
/**
 * Constructor: Initializes an empty tree.
 * root should be nullptr.
 * greatestIDEver should be 1.
 */
BinaryTree::BinaryTree() {
    // YOUR CODE GOES HERE
}
#endif


#ifdef USE_STUDENT_DESTRUCTOR_IMPL
/**
 * Destructor: Frees all dynamically allocated memory.
 * (Hint: Define a recursive helper function *inside* this #ifdef block)
 */
BinaryTree::~BinaryTree() {
    // YOUR CODE GOES HERE
}
#endif


#ifdef USE_STUDENT_GETSUBTREEWEIGHT_IMPL
/**
 * Calculates the average weight of the subtree rooted at node `id`.
 * (Hint: You can call this->getNodeById(id) to get the node.)
 */
double BinaryTree::getSubtreeWeight(int id) {
    // YOUR CODE GOES HERE
}
#endif


#ifdef USE_STUDENT_ENUMERATEBFS_IMPL
/**
 * Enumerates the node IDs in BFS order, printing them.
 * Output format: "id1 id2 id3 \n"
 */
void BinaryTree::enumerateBFS() {
    // YOUR CODE GOES HERE
}
#endif


#ifdef USE_STUDENT_GETNODEBYID_IMPL
/**
 * Finds and returns a pointer to the node with the given `id`.
 * (Hint: Define a recursive helper function *inside* this #ifdef block)
 */
Node* BinaryTree::getNodeById(int id) {
    // YOUR CODE GOES HERE
}
#endif


#ifdef USE_STUDENT_GETLEVELBYID_IMPL
/**
 * Finds the level of the node with the given `id`. Root is level 0.
 * (Hint: A BFS is a good way to find level)
 */
int BinaryTree::getLevelById(int id) {
    // YOUR CODE GOES HERE
}
#endif


#ifdef USE_STUDENT_GETLEFTMORTRIGHTMOSTDISTANCE_IMPL
/**
 * Finds the distance between the leftmost and rightmost nodes.
 * (Hint: You can call this->getLevelById(id) on the nodes.)
 */
int BinaryTree::getLeftmostRightmostDistance() {
    // YOUR CODE GOES HERE
}
#endif


#ifdef USE_STUDENT_GETFARTHESTLEAFID_IMPL
/**
 * Finds the ID of the *leftmost* leaf node farthest from the root.
 * (Hint: Define a recursive helper function *inside* this #ifdef block)
 */
int BinaryTree::getFarthestLeafId() {
    // YOUR CODE GOES HERE
}
#endif


#ifdef USE_STUDENT_GETCLOSESTLEAFID_IMPL
/**
 * Finds the ID of the *leftmost* leaf node closest to the root.
 * (Hint: Define a recursive helper function *inside* this #ifdef block)
 */
int BinaryTree::getClosestLeafId() {
    // YOUR CODE GOES HERE
}
#endif


#ifdef USE_STUDENT_CHANGEROOT_IMPL
/**
 * Changes the root of the tree to the node with `newRootId`.
 * Fails if the new root has 2 children.
 * (Hint: You can call this->getNodeById(id) to get the node.)
 */
void BinaryTree::changeRoot(int newRootId) {
    // YOUR CODE GOES HERE
}
#endif


#ifdef USE_STUDENT_ADDNODE_IMPL
/**
 * Adds a new node with `value` as a child of `parent`.
 * New node's ID should be greatestIDEver + 1.
 * Don't forget to increment greatestIDEver.
 */
void BinaryTree::addNode(Node* parent, int value, bool isLeft) {
    // YOUR CODE GOES HERE
}
#endif


#ifdef USE_STUDENT_REMOVENODE_IMPL
/**
 * Removes the node with `id` from the tree.
 * Only works if the node has 0 or 1 child.
 * (Hint: You can call this->getNodeById(id) to get the node.)
 */
void BinaryTree::removeNode(int id) {
    // YOUR CODE GOES HERE
}
#endif


#ifdef USE_STUDENT_PRINTTREEINORDER_IMPL
/**
 * Prints the tree in In-Order (LNR)
 * Format: "Node value: [v], Node Id: [id]\n"
 * (Hint: Define a recursive helper function *inside* this #ifdef block)
 */
void BinaryTree::printTreeInOrder() {
    // YOUR CODE GOES HERE
}
#endif
