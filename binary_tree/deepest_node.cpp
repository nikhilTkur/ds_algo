#include <iostream>
#include <queue>
#include "binary_tree.h"

using namespace std;

void findDeepest(Node * root)
{
    if (root == nullptr) return;
    queue<Node *> q;
    q.push(root);

    while(!q.empty())
    {
        Node * temp = q.front();
        q.pop();

        if (q.size() == 0) cout << "deepest node is " << temp->data;

        if (temp->left) q.push(temp->left);
        if (temp->right) q.push(temp->right);
    }

}
int main()
{
    Node* root =  createNode(1);
    root->left =  createNode(2);
    root->right =  createNode(3);
    root->left->left =  createNode(4);
    root->right->left =  createNode(9);
    root->right->right =  createNode(6);
    root->right->left->right =  createNode(7);
    root->right->right->right =  createNode(8);
    root->right->left->right->left =  createNode(5);
 
    findDeepest(root);

 
    return 0;
}