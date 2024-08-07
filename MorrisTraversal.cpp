#include <iostream>

using namespace std;

struct tNode {
    int data;
    tNode* left;  // Corrected: Use tNode* instead of int for left and right pointers
    tNode* right;
};

void MorrisTraversal(tNode* root) {
    tNode* current, *pre;

    if (root == NULL) {
        return;
    }

    current = root;
    while (current != NULL) {
        if (current->left == NULL) {
            cout << current->data << " ";
            current = current->right;
        } else {
            pre = current->left;
            while (pre->right != NULL && pre->right != current) {
                pre = pre->right;
            }

            if (pre->right == NULL) {
                pre->right = current;
                current = current->left;
            } else {
                pre->right = NULL;
                cout << current->data << " ";  // Corrected: Fixed the output statement
                current = current->right;
            }
        }
    }
}

tNode* newNode(int data) {
    tNode* node = new tNode();
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return node;  // Corrected: Added return statement to newNode function
}

int main() {
    tNode* root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);

    MorrisTraversal(root);

    return 0;
}
