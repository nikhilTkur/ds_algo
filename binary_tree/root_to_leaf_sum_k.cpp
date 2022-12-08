#include <iostream>
#include "binary_tree.h"

bool hasSumFromRootToLeaf(Node * root, int sum)
{
    if (root == nullptr) return false;

    int checkSum = sum - root->data;

    if (checkSum == 0 && root->left == nullptr && root->right == nullptr)
    {
        return true;
    }

    bool ans = false;

    if (root->left)
    {
        ans = ans || hasSumFromRootToLeaf(root->left, checkSum);
    }
    if (root->right)
    {
        ans = ans || hasSumFromRootToLeaf(root->right, checkSum);
    }
    return ans;
}

int main()
{
    int sum = 21;
 
    /* Constructed binary tree is
              10
            /   \
          8      2
        /  \    /
      3     5  2
    */
    Node * root = createNode(10);
    root->left = createNode(8);
    root->right = createNode(2);
    root->left->left = createNode(3);
    root->left->right = createNode(5);
    root->right->left = createNode(2);
 
    // Function call
    if (hasSumFromRootToLeaf(root, sum))
        printf("There is a root-to-leaf path with sum %d",
               sum);
    else
        printf("There is no root-to-leaf path with sum %d",
               sum);
 
    getchar();
    return 0;
}