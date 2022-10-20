#include <iostream>
#include <stack>
#include "binary_tree.h"

using namespace std;

void inorder_without_recursion(Node * root)
{
    stack<Node *> st;
    Node * current = root;

    while (current != nullptr || !st.empty())
    {
        // here we try to find the left most leaf of the tree to the bottom

        while (current != nullptr)
        {
            st.push(current);
            current = current->left;
        }

        current = st.top();
        st.pop();

        cout << current->data << " ";
        current = current->right;
    } 

}

int main()
{
  
    /* Constructed binary tree is
              1
            /   \
          2      3
        /  \
      4     5
    */
    Node *root = createNode(1);
    root->left        = createNode(2);
    root->right       = createNode(3);
    root->left->left  = createNode(4);
    root->left->right = createNode(5);
  
    inorder_without_recursion(root);
    return 0;
}