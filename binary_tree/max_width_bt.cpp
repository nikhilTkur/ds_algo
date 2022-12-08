#include <iostream>
#include "binary_tree.h"
#include <queue>
#include <algorithm>

using namespace std;

int maxWidth(Node * root)
{
    if (root == nullptr) return 0;

    queue<Node *> q;
    q.push(root);
    int max_width = 0;

    while (!q.empty())
    {
        int count = q.size();
        max_width = max (count, max_width);
        while (count--)
        {
            Node * temp = q.front();
            q.pop();

            if (temp->left) q.push(temp->left);
            if (temp->right) q.push(temp->right);
        } 
    }
    return max_width;
}

int main()
{
    Node* root =   createNode(1);
    root->left =   createNode(2);
    root->right =   createNode(3);
    root->left->left =   createNode(4);
    root->left->right =   createNode(5);
    root->right->right =   createNode(8);
    root->right->right->left =   createNode(6);
    root->right->right->right =   createNode(7);
  
    /*   Constructed Binary tree is:
                 1
               /   \
             2      3
           /  \      \
          4    5      8
                    /   \
                   6     7    */
  
    // Function call
    cout << "Maximum width is " << maxWidth(root) << endl;
    return 0;
}