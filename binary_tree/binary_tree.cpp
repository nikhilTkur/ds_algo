#include <iostream>
#include <queue>

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
}

void inorder(Node* temp)
{
    if (!temp)
        return;
    
    inorder(temp->left);
    std::cout << temp->data << " ";
    inorder(temp->right);
}

int main()
{
    Node * root = createNode(10);
    root->left = createNode(11);
    root->left->left = createNode(7);
    root->right = createNode(9);
    root->right->left = createNode(15);
    root->right->right = createNode(8);

    std::cout << "Inorder traversal of the tree before insertion is ";
    inorder(root);
    std::cout << std::endl;

    int key = 12;
    root = InsertNode(root , key);

    std::cout << "Inorder traversal of the tree after insertion is ";
    inorder(root);
    std::cout << std::endl;

    return 0;

}