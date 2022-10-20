#include <stack>
#include <iostream>
#include "binary_tree.h"

using namespace std;

void preorder_with_iteration(Node * root)
{
    if (root == nullptr) return;

    stack<Node *> st;
    
    Node * current = root;

    while (current != nullptr || !st.empty())
    {
        while (current != nullptr)
        {
            cout << current->data << " ";
            if (current->right)
            {
                st.push(current->right);
            }            

            current = current->left;
        }

        current = st.top();
        st.pop();
    }
}

int main()
{
    Node* root = createNode(10);
    root->left = createNode(20);
    root->right = createNode(30);
    root->left->left = createNode(40);
    root->left->left->left = createNode(70);
    root->left->right = createNode(50);
    root->right->left = createNode(60);
    root->left->left->right = createNode(80);
 
    preorder_with_iteration(root);
 
    return 0;
}