#include <iostream>
#include "binary_tree.h"


int findLevel (Node * root, Node * ptr, int level)
{
    if (root == nullptr) return 0;

    if (root == ptr) return level;

    int leftLevel = findLevel(root->left, ptr, level + 1);

    if (!leftLevel) return leftLevel;
    else return findLevel(root->right, ptr, level + 1);

}

bool isSibling (Node * root, Node * a, Node * b)
{
    if (root == nullptr) return false;

    return (root->left == a && root->right == b
             || root->left == b && root->right == a
             || isSibling (root->left, a , b)
             || isSibling (root->right, a, b));
}

bool isCousin(Node * root, Node * a, Node * b)
{
    return ((findLevel(root, a , 1) == findLevel(root, b, 1)) && !isSibling(root, a, b));
}

int main ()
{
    Node* root = createNode(1);
    root->left = createNode(2);
    root->right = createNode(3);
    root->left->left = createNode(4);
    root->left->right = createNode(5);
    root->left->right->right = createNode(15);
    root->right->left = createNode(6);
    root->right->right = createNode(7);
    root->right->left->right = createNode(8);
 
    struct Node *Node1, *Node2;
    Node1 = root->left->left;
    Node2 = root->right->right;

    if (isCousin(root, Node1, Node2))
        std::cout << "Yes\n";
    else
        std::cout << "No\n";
}