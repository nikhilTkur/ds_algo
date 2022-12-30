#include <bits/stdc++.h>

using namespace std;

class node
{
    public:
    int key;
    node * left;
    node * right;
    int count;
};

node * newNode(int data)
{
    node * temp = new node();
    temp->key = data;
    temp->left = temp->right = nullptr;
    temp->count = 1;
    return temp;
}

void inorder (node * root)
{
    if (root == nullptr)
    {
        return;
    }
    inorder(root->left);
    cout << root->key << "(" << root->count << ") ";
    inorder(root->right);
}

node * insert(node * root, int key)
{
    if (root == nullptr)
    {
        return newNode(key);
    }

    if (key < root->key)
    {
        root->left = insert(root->left , key);
    }
    else if (key > root->key)
    {
        root->right = insert(root->right, key);
    }
    else
    {
        (root->count)++;
    }

    return root;
}

node * minValueNode(node * root)
{
    node * current = root;
    while(current->left)
    {
        current = current->left;
    }
    return current;
}

node * deleteNode(node * root, int key)
{
    if (root == nullptr) return nullptr;

    if (key < root->key)
    {
        root->left = deleteNode(root->left , key);
    }
    else if (key > root->key)
    {
        root->right = deleteNode(root->right, key);
    }
    else
    {
        if (root->count > 1)
        {
            (root->count)--;
            return root;
        }
        if (root->left == nullptr)
        {
            node * temp = root->right;
            free(root);
            return temp;
        }
        else if (root->right == nullptr)
        {
            node * temp = root->left;
            free(root);
            return temp;
        }
        else
        {
            node * temp = minValueNode(root->right);
            root->key = temp->key;
            root->count = temp->count;

            temp->count = 0;
            root->right = deleteNode(root->right, temp->key);
        }
    }

    return root;
}

// Driver Code
int main()
{
    /* Let us create following BST
            12(3)
        /     \
    10(2)     20(1)
    / \
    9(1) 11(1) */
    struct node *root = NULL;
    root = insert(root, 12);
    root = insert(root, 10);
    root = insert(root, 20);
    root = insert(root, 9);
    root = insert(root, 11);
    root = insert(root, 10);
    root = insert(root, 12);
    root = insert(root, 12);
  
    cout << "Inorder traversal of the given tree " 
         << endl;
    inorder(root);
  
    cout << "\nDelete 20\n";
    root = deleteNode(root, 20);
    cout << "Inorder traversal of the modified tree \n";
    inorder(root);
  
    cout << "\nDelete 12\n" ;
    root = deleteNode(root, 12);
    cout << "Inorder traversal of the modified tree \n";
    inorder(root);
  
    cout << "\nDelete 9\n";
    root = deleteNode(root, 9);
    cout << "Inorder traversal of the modified tree \n";
    inorder(root);
  
    return 0;
}