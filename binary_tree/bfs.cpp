#include "binary_tree.h"
#include <iostream>

void printCurrentLevel(Node * node, int level)
{
    if (node == nullptr) return;

    if (level == 1) std::cout << node->data << " ";
    else if (level > 1)
    {
        printCurrentLevel(node->left, level -1);
        printCurrentLevel(node->right, level -1);
    }
}

void printLevelOrder(Node * root)
{
    int h = height(root);
    for (int i = 1 ; i <= h; i++)
    {
        printCurrentLevel(root, i);
    }
}


int main()
{
    Node * root = createNode(1);
    root->left = createNode(2);
    root->right = createNode(3);
    root->left->left = createNode(4);
    root->left->right = createNode(5);

    printLevelOrder(root);
    
    return 0;
}