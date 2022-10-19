#include <iostream>
#include <queue>

#include "binary_tree.h"

Node * InsertNode(Node* root, int data)
{
    if (root == nullptr)
    {
        root = createNode(data);
        return root;
    }

    std::queue <Node*> q;
    q.push(root);

    while(!q.empty())
    {
        Node* temp = q.front();
        q.pop();

        if (temp->left)
        {
            q.push(temp->left);
        }
        else
        {
            temp->left = createNode(data);
            return root;
        }
        if (temp->right)
        {
            q.push(temp->right);
        }
        else
        {
            temp->right = createNode(data);
            return root;
        }
    }
    return nullptr;
}

// delete node
Node * deleteNode(Node * root , int key)
{
    if (!root) return nullptr;

    if (root->left == nullptr && root->right == nullptr)
    {
        if (root->data == key) return nullptr;
        else return root;
    }

    std::queue <Node*> q;

    q.push(root);

    Node * temp;
    Node * key_node = nullptr;
    Node * last;

    while (!q.empty())
    {
        temp = q.front();
        q.pop();

        if (temp->data == key)
        {
            key_node = temp;
        }

        if (temp->left)
        {
            last = temp;
            q.push(temp->left);
        }
        if (temp->right)
        {
            last = temp;
            q.push(temp->right);
        }
    }


    // by now we will have the key_node to be deleted and temp pointing to the rightmost node
    if (key_node)
    {
        key_node->data = temp->data;

        if (last->left == temp) last->left == nullptr;
        else last->right == nullptr;        
        delete (temp);
    }

    return root;
}

int main()
{
    Node * root = createNode(10);
    root->left = createNode(11);
    root->left->left = createNode(7);
    root->left->right = createNode(12);
    root->right = createNode(9);
    root->right->left = createNode(15);
    root->right->right = createNode(8);

    std::cout << "Inorder traversal of the tree before deletion is ";
    inorder(root);
    std::cout << std::endl;

    int key = 11;
    // root = InsertNode(root , key);
    root = deleteNode(root , key);

    std::cout << "Inorder traversal of the tree after deletion is ";
    inorder(root);
    std::cout << std::endl;

    return 0;

}