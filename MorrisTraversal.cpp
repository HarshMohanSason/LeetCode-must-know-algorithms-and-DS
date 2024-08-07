
/*        This Algorithm is used to traverse a binary tree in O(1) space. No recursion or stack is being used

          Note this is an inorder traversal. Pre or Post slightly differ in code

          Very simple steps: 

          * initialize two pointers current and pre
          * initialize current = root; 
          1. Check if left subtree exists. If it does not, simply output data of right subtree
          2. If left subtree does exist: 
              * make the pre = current->left; 
              * Traverse to the bottom right node of the left subtree i.e while(pre->right != null && pre->right != current)
          3. Once pre is pointing to the rightmost node in the left subtreee: 
              * check if pre->right != NULL i.e if there is no right node, make the pre->right = current (which is the root->left initially)
              * make current move one node down. 
              If pre->right != NULL , then make the pre->right = NULL and output the data. and make the current move to the right node (current = current->right)
         
                
        
*/


#include <iostream>

using namespace std;

struct tNode {
    int data;
    tNode* left;  
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
                cout << current->data << " ";  
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
    return node;  
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
