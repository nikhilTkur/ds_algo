#include <iostream>
#include <map>

class Node
{
    public:
        int data;
        Node* left;
        Node* right;
    
    Node(int val)
    {
        data = val;
        left = nullptr;
        right = nullptr;
    } 
};

int main()
{
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);

    root->left->left = new Node(4);

    return 0;
}