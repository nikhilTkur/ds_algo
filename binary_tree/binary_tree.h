#include <iostream>

struct Node
{
    int data;
    Node* left;
    Node* right;
};

Node* createNode(int data)
{
    Node* newNode = new Node();
    if (!newNode)
    {
        std::cout << "Memory Error \n";
        return nullptr;
    }
    newNode->data = data;
    newNode->left = newNode->right = nullptr;
    return newNode;
}

int height (Node * node)
{
    if (node == nullptr)
    {
        return 0;
    }
    else
    {
        int left = height(node->left);
        int right = height(node->right);

        if (left > right)
        {
            return left + 1;
        }
        else
        {
            return right + 1;        
        }
    }
}

void inorder(Node* temp)
{
    if (!temp)
        return;
    
    inorder(temp->left);
    std::cout << temp->data << " ";
    inorder(temp->right);
}