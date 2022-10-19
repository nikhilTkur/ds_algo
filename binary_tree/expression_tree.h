#include <iostream>

class Node
{
    public:
    char value;
    Node * left;
    Node * right;
    Node * next;

    Node(char c)
    {
        this->value = c;
        this->left = nullptr;
        this->right = nullptr;
    }
    Node()
    {
        left = nullptr;
        right = nullptr;
    }

    friend class Stack;
    friend class ExpressionTree;
};

class Stack
{
    Node * head = nullptr;
public:
    void push(Node *);
    Node * pop();
    friend class ExpressionTree;
};

class ExpressionTree
{
public:
    void inorder(Node * node);
};
