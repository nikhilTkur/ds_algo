#include <iostream>
#include <stack>
#include "binary_tree.h"

using namespace std;

void postorder_with_iteration(Node * root)
{
    stack<Node *> st1;
    stack<Node *> st2;

    st1.push(root);

    Node * temp;
    
    while (!st1.empty())
    {
        temp = st1.top();
        st1.pop();
        st2.push(temp);

        if (temp->left) st1.push(temp->left);
        if (temp->right) st1.push(temp->right);
    }

    while (!st2.empty())
    {
        cout << st2.top()->data << " ";
        st2.pop();
    }
}

int main()
{
    // Let us construct the tree
    // shown in above figure
    Node* root = NULL;
    root = createNode(1);
    root->left = createNode(2);
    root->right = createNode(3);
    root->left->left = createNode(4);
    root->left->right = createNode(5);
    root->right->left = createNode(6);
    root->right->right = createNode(7);
 
    postorder_with_iteration(root);
 
    return 0;
}