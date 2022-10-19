#include "expression_tree.h"
#include <iostream>


void ExpressionTree::inorder(Node * node)
{
    if (node == nullptr)
        return;
    else
    {
        inorder(node->left);
        std::cout << node->value << "  ";
        inorder(node->right);
    }
}

void Stack::push(Node * node)
{
    if (head == nullptr)
    {
        head = node;
    }
    else
    {
        node->next = head;
        head = node;
    }
}

Node * Stack::pop()
{
    Node * p = head;
    head = head->next;
    return p;   
}

int main()
{
    std::string s = "ABC*+D/";
    Stack st;
    ExpressionTree et;

    Node * x , * y , * z;

    int length = s.size();

    for (int i = 0 ;  i < length ; i++)
    {
        if (s[i] == '+' || s[i] == '-' || s[i] == '*'|| s[i] == '/' || s[i] == '^')
        {
            z = new Node(s[i]);
            x = st.pop();
            y = st.pop();
            z->left = y;
            z->right = x;
            st.push(z);
        }
        else
        {
            z = new Node(s[i]);
            st.push(z);
        }

    }

    std::cout << "Inorder traversal of the expression tree is " << std::endl;

    et.inorder(z);
}