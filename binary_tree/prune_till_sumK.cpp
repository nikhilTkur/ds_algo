#include <iostream>
#include <algorithm>
#include "binary_tree.h"


// a function that returns the pruned tree

Node * pruneTree(Node * root, int & sum, int limitSum)
{
    if (root == nullptr) return nullptr;

    int rightSum = sum + root->data, leftSum = sum + root->data;
    root->left = pruneTree(root->left, leftSum, limitSum);
    root->right = pruneTree(root->right , rightSum, limitSum);

    sum = std::max (leftSum, rightSum);

    if (sum < limitSum)
    {
        // need to prune the tree
        free(root);
        root = nullptr;
    }

    return root;
}

int main()
{
    int k = 45, sum = 0;
    struct Node *root = createNode(1);
    root->left = createNode(2);
    root->right = createNode(3);
    root->left->left = createNode(4);
    root->left->right = createNode(5);
    root->right->left = createNode(6);
    root->right->right = createNode(7);
    root->left->left->left = createNode(8);
    root->left->left->right = createNode(9);
    root->left->right->left = createNode(12);
    root->right->right->left = createNode(10);
    root->right->right->left->right = createNode(11);
    root->left->left->right->left = createNode(13);
    root->left->left->right->right = createNode(14);
    root->left->left->right->right->left = createNode(15);

    std::cout <<"Tree before truncation\n";
    inorder(root);
 
    root = pruneTree(root, sum, k ); // k is 45
 
    std::cout <<"\n\nTree after truncation\n";
    inorder(root);
 
    return 0;
}