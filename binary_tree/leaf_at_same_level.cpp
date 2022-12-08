#include <iostream>
#include "binary_tree.h"

bool leaf_at_same_level(Node * root, int currLeafLevel, int & leafLevel)
{
    if (root == nullptr) return true;

    if (root->left == nullptr && root->right == nullptr)
    {
        if (leafLevel == 0)
        {
            leafLevel = currLeafLevel;
            return true;
        }
        else
        {
            return currLeafLevel == leafLevel;
        }
    }
    return leaf_at_same_level (root->left, currLeafLevel + 1, leafLevel) && 
           leaf_at_same_level (root->right, currLeafLevel + 1, leafLevel);
}

int main()
{
    Node *root = createNode(12);
    root->left = createNode(5);
    root->left->left = createNode(3);
    root->left->right = createNode(9);
    root->left->left->left = createNode(1);
    root->left->right->left = createNode(1);
    int level = 0, leaflevle = 0;
    if (leaf_at_same_level(root, level , leaflevle))
        std::cout << "Leaves are at same level\n";
    else
        std::cout << "Leaves are not at same level\n";
    return 0;
}