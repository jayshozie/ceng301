#include "BinaryTree.h"

// Q2
Node* BinaryTree::findParent(Node* parent, Node* node) {
    if(parent != nullptr && (parent->left != nullptr || parent->right != nullptr)) {
        if(parent->left == node || parent->right == node) {
            return parent;
        }
        findParent(parent->left, node);
        findParent(parent->right, node);
    }
}
void BinaryTree::removeNode(int id) {
    Node* node = this->getNodeById(id);
    if(node == this->root) {
        if(node->left != nullptr && node->right == nullptr) {
            this->root = node->left;
            delete node;
            return;
        }
        else if(node->left == nullptr && node->right != nullptr) {
            this->root = node->right;
            delete node;
            return;
        }
        else if(node->left == nullptr && node->right == nullptr) {
            delete node;
            return;
        }
        else {
            return;
        }
    }
    Node* parent = this->findParent(this->root, node);
    if(node->right == nullptr && node->left == nullptr) {
        if(parent->left == node) {
            parent->left = nullptr;
        }
        else if(parent->right == node) {
            parent->right = nullptr;
        }
        else {
            return;
        }
        delete node;
        return;
    }
    else if(node->right == nullptr && node->left != nullptr) {
        // single child, left full
        if(parent->left == node) {
            parent->left = node->left;
            delete node;
            return;
        }
        else if(parent->right == node) {
            parent->right = node->left;
            delete node;
            return;
        }
        else {
            return;
        }
    }
    else if(node->right != nullptr && node->left == nullptr) {
        // single child, right full
        if(parent->left == node) {
            parent->left = node->right;
            delete node;
            return;
        }
        else if(parent->right == node) {
            parent->right = node->right;
            delete node;
            return;
        }
        else {
            return;
        }
    }
    else {
        // multiple childs, do nothing
        return;
    }
}
