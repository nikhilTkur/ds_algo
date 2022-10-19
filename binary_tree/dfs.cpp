#include <iostream>
#include "binary_tree.h"

int main()
{
    Node * root = createNode(1);
    root->left = createNode(2);
    root->right = createNode(3);
    root->left->left = createNode(4);
    root->left->right = createNode(5);

    std::cout << " Inorder DFS of the tree is " << std::endl;
    inorder(root);
}