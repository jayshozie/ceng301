// BinaryTree.h
#ifndef BINARYTREE_H
#define BINARYTREE_H

#include <vector> // For STL classes

// Node class definition
class Node {
public:
    int id;
    int value; // Weight of the node
    Node* left;
    Node* right;

    Node(int id, int value) : id(id), value(value), left(nullptr), right(nullptr) {}
};

// BinaryTree class definition
class BinaryTree {
public:
    Node *root;
    int greatestIDEver;

    BinaryTree();
    ~BinaryTree();

    // Function prototypes
    double getSubtreeWeight(int id);
    void enumerateBFS();
    Node* getNodeById(int id);
    int getLevelById(int id);
    int getLeftmostRightmostDistance();
    int getFarthestLeafId();
    int getClosestLeafId();
    void changeRoot(int newRootId);
    void addNode(Node* parent, int value, bool isLeft);
    void removeNode(int id);
    void printTreeInOrder();
    
    // HELPER MEMBER FUNCTIONS
private:
    // helper for getSubtreeWeight
    void getSubtreeWeight(Node* node, long long& sum, int& count);

    // helper for enumerateBFS
    void enumerateBFS(Node* start);

    // helper for getNodeById
    Node* getNodeById(Node* node, int id);

    // helper for getLevelById
    int getLevelById(Node* node, int id, int currentLevel);

    // helpers for getLeftmostRightMostDistance
    Node* getLeftmost(Node* node);
    Node* getRightmost(Node* node);

    // helper for getFarthestLeafId
    void getFarthestLeafId(Node* node, int depth, int& bestDepth, int& bestId);

    // helper for getClosestLeafId
    void getClosestLeafId(Node* node, int depth, int& bestDepth, int& bestId);

    // helper for changeRoot
    Node* changeRoot(Node* curr, Node* target);
    // this actually finds the parent of the given target node, but it doesn't
    // compile with that for some reason, that's why the naming is a little bit
    // off

    // helper for addNode
    void addNode(Node* parent, int value, bool isLeft, int* outNewid, bool& added);

    // helper for removeNode
    bool removeNode(Node* curr, Node* parent, int id);

    // helper for printTreeInOrder
    void printTreeInOrder(Node* node);

    // helper for destructor
    void destroy(Node* node);
};

#endif // BINARYTREE_H
