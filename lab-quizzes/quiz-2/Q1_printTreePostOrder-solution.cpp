#include "BinaryTree.h"

#ifdef USE_STUDENT_Q1_IMPL

// Q1: Post-Order
void BinaryTree::printTreePostOrder(Node* node) {
    if(node != nullptr) {
        printTreePostOrder(node->left);
        printTreePostOrder(node->right);
        std::cout << "Node value: " << node->value << ", Node Id: " << node->id << std::endl;
    }
}
void BinaryTree::printTreePostOrder() {
    this->printTreePostOrder(this->root);
}

#endif
