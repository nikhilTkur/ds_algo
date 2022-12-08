#include <iostream>
#include "binary_tree.h"
#include <queue>

using namespace std;
void deleteTree(Node * root)
{
    if (root == nullptr) return;
    
    queue<Node *> q;

    q.push(root);

    while(!q.empty())
    {
        Node * temp = q.front();
        q.pop();

        if (temp->left) q.push(temp->left);
        if (temp->right) q.push(temp->right);
        free (temp);
    }

}

int main()
{
    // create a binary tree
    Node *root =  createNode(15);
    root->left = createNode(10);
    root->right = createNode(20);
    root->left->left = createNode(8);
    root->left->right = createNode(12);
    root->right->left = createNode(16);
    root->right->right = createNode(25);
  
    //delete entire binary tree
    deleteTree(root);
  
    return 0;
}