#include <iostream>
#include "binary_tree.h"
#include <algorithm>
using namespace std;

int diameter(Node * root)
{
    if (root == nullptr) return 0;

    int lh = height(root->left);
    int rh = height(root->right);

    int ld = diameter(root->left);
    int rd = diameter(root->right);

    return max(1 + rh + lh , max(rd, ld));
}

int main()
{
 
    /* Constructed binary tree is
            1
            / \
        2     3
        / \
    4     5
    */
    Node* root = createNode(1);
    root->left = createNode(2);
    root->right = createNode(3);
    root->left->left = createNode(4);
    root->left->right = createNode(5);
 
    // Function Call
    cout << "Diameter of the given binary tree is "
         << diameter(root);
 
    return 0;
}