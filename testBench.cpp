#include <iostream>

int main()
{
    int avg;
    std::cout << avg << std::endl;
}

<details>
    <summary> Solution </summary>

```cpp
class SearchTree {
public:
    int getMax() {
        if(this->root == nullptr) {
            throw new NoSuchElementException();
        }
        return getMax(root);
    }
private:
    int getMax(IntTreeNode* root) {
        if(root->left == nullptr) {
            return root->data;
        }
        else {
            while(root->right != nullptr) {
                root = root->right;
            }
            return root->data;
        }
    }
}
```
</details>
