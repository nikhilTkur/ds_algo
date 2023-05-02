#include <bits/stdc++.h>

using namespace std;

class Node
{
    public:
    int data;
    Node * left;
    Node * right;
};

void b2ll(Node * root, Node ** head)
{
    if (root == nullptr)
    {
        return;
    }

    static Node * prev = nullptr;    
    b2ll(root->left, head);

    if (prev == nullptr)
    {
        *head = root;
    }
    else
    {
        root->left = prev;
        prev->right = root;
    }
    prev = root;

    b2ll(root->right, head);
}

/* Helper function that allocates a new node with the
   given data and NULL left and right pointers. */
Node* newNode(int data)
{
    Node* new_node = new Node();
    new_node->data = data;
    new_node->left = new_node->right = NULL;
    return (new_node);
}
 
/* Function to print nodes in a given doubly linked list */
void printList(Node* node)
{
    while (node != NULL) {
        cout << node->data << " ";
        node = node->right;
    }
}
 
// Driver Code
int main()
{
    // Let us create the tree shown in above diagram
    Node* root = newNode(10);
    root->left = newNode(12);
    root->right = newNode(15);
    root->left->left = newNode(25);
    root->left->right = newNode(30);
    root->right->left = newNode(36);
 
    // Convert to DLL
    Node* head = NULL;
    b2ll(root, &head);
 
    // Print the converted list
    printList(head);
 
    return 0;
}