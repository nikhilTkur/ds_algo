#include <bits/stdc++.h>

using namespace std;

struct node
{
    int key;
    node * left, *right;
};

node* newNode(int item)
{
    node * temp = new node();
    temp->key = item;
    temp->left = temp->right = nullptr;
    return temp;    
}

node * insert(node* node, int key)
{
    if (node == nullptr)
    {
        return newNode(key);
    }

    if (key < node->key)
    {
        node->left = insert(node->left , key);
    }
    else if (key > node->key)
    {
        node->right = insert(node->right , key);
    }
    return node;
}

void inorder(node * root)
{
    if (root != NULL)
    {
        inorder(root->left);
        cout << root->key << " ";
        inorder(root->right);
    }
}

int height(node * root)
{
    if (root == nullptr)
    {
        return 0;
    }

    int lh = height(root->left);
    int rh = height(root->right);

    if (lh > rh)
    {
        return lh + 1;

    }
    else 
    {
        return rh + 1;
    }
}

void printGivenLevel(node * root, int level)
{
    if (root == nullptr)
    {
        return;
    }

    if (level == 1)
    {
        cout << root->key << " ";
    }
    else if (level > 1)
    {
        printGivenLevel(root->left , level-1);
        printGivenLevel(root->right , level-1);
    }
}

void printLevelOrder(node * root)
{
    int h = height(root);

    for (int i = 1 ; i <= h; i++)
    {
        printGivenLevel(root, i);
        cout << endl;
    }
}

void preOrder(struct node* root)
{
    if (root != NULL) {
        cout << " " << root->key;
        preOrder(root->left);
        preOrder(root->right);
    }
}

node * minNode(node * root)
{
    node * current = root;

    while (current && current->left)
    {
        current = current->left;
    }

    return current;
}

node * deleteNode(node * root, int key)
{
    if (root == nullptr)
    {
        return root;
    }

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
        // this is the key to be deleted, need to check the cases of 1 child and 2 child separately
        if (root->left == nullptr && root->right == nullptr)
        {
            return nullptr;
        }
        if (root->left == nullptr && root->right)
        {
            node * temp = root->right;
            free(root);
            return temp;
        }
        else if (root->right == nullptr && root->left)
        {
            node* temp = root->left;
            free(root);
            return temp;
        }

        node * temp = minNode(root->right);

        root->key = temp->key;
        root->right = deleteNode(root->right, temp->key);
    }

    return root;
}

bool iterativeSearch(node * root, int key)
{
    node * temp = root;
    while (temp != nullptr)
    {
        if (key > temp->key)
        {
            temp = temp->right;
        }
        else if (key < temp->key)
        {
            temp = temp->left;
        }
        else
        {
            return true;
        }
    }
    return false;
}

node * sortedArrayToBST(int arr[], int start, int end)
{
    if (start > end)
    {
        return nullptr;
    }

    int mid = (start + end) / 2;
    node * root = newNode(arr[mid]);

    root->left = sortedArrayToBST(arr, start, mid-1);
    root->right = sortedArrayToBST(arr, mid+1, end);

    return root;
}


// ------------------------------------------------------------------------------

// sorted linked list to a bst

class lnode
{
    public:
    int data;
    lnode * next;
};

int countlnode(lnode * head)
{
    int count = 0;

    lnode * temp = head;

    while(temp)
    {
        count++;
        temp = temp->next;
    }

    return count;
}

node * listToBSTUtil(lnode ** head, int n)
{
    if (n <= 0)
    {
        return nullptr;
    }

    node * left = listToBSTUtil(head, n/2);

    node * root = newNode((*head)->data);
    (*head) = (*head)->next;
    root->left = left;

    root->right = listToBSTUtil(head, n - n/2 -1);

    return root;
}

node * listToBST(lnode * head)
{
    int n = countlnode(head);

    return listToBSTUtil(&head, n);
}

void push(lnode ** head, int data)
{
    lnode * newNode = new lnode();

    newNode->data = data;

    newNode->next = *head;

    *head = newNode;
}

// ------------------------------------------------------------------------------

// construct a BST from the pre order traversal

node * constructBSTUtil(int pre[], int size, int &preIndex, int low, int high)
{
    if (preIndex >= size || low > high)
    {
        return nullptr;
    }

    node * root = newNode(pre[preIndex]);
    preIndex = preIndex + 1;

    if (low == high)
    {
        return root;
    }

    int rightIndex;

    for (rightIndex = low; rightIndex <= high ; rightIndex++)
    {
        if (pre[rightIndex] > root->key)
        {
            break;
        }
    }

    root->left = constructBSTUtil(pre, size, preIndex, preIndex, rightIndex - 1);
    root->right = constructBSTUtil(pre, size, preIndex, rightIndex, high);

    return root;
}

node * constructBST(int pre[], int size)
{
    int preIndex = 0;

    return constructBSTUtil(pre, size, preIndex, 0, size-1);
}

// ------------------------------------------------------------------------------

// create BST from level order

void levelOrderToBSTUtil(node ** root, int data)
{
    if ((*root) == nullptr)
    {
        (*root) = newNode(data);
        return;// root;
    }
    if (data <= (*root)->key)
    {
       levelOrderToBSTUtil(&(*root)->left , data);
    }
    else
    {
        levelOrderToBSTUtil(&(*root)->right , data);
    }
    //return root;
}

node * levelOrderBST(int arr[], int n)
{
    if (n == 0) return nullptr;
    node * root = nullptr;
    for (int i = 0 ; i < n ; i++)
    {
        levelOrderToBSTUtil(&root, arr[i]);
    }
    return root;
}

// ------------------------------------------------------------------------------

// to find the kth smallest elememt in the BST
int count_k_sm = 0;
node * ksmallestBST(node * root, int k)
{
    if (root == nullptr)
    {
        return nullptr;
    }

    node * left = ksmallestBST(root->left , k);

    if (left != nullptr)
    {
        return left;
    }

    count_k_sm++;

    if (count_k_sm == k)
    {
        return root;
    }

    return ksmallestBST(root->right, k);
}

void printKSmallestBST(node * root, int k)
{
    node * result = ksmallestBST(root, k);

    if (result == nullptr) cout << " no of nodes in the bst is less than k " << endl;
    else cout << " kth smallest element in the BST is " << result->key << endl;
}

// ------------------------------------------------------------------------------

// Driver Code
int main()
{
      
    /* Let us create following BST 
              50 
           /     \ 
          30      70 
         /  \    /  \ 
       20   40  60   80 
   */
    struct node* root = NULL;
  
    // Inserting value 50
    root = insert(root, 50);
  
    // Inserting value 30
    insert(root, 30);
  
    // Inserting value 20
    insert(root, 20);
  
    // Inserting value 40
    insert(root, 40);
  
    // Inserting value 70
    insert(root, 70);
  
    // Inserting value 60
    insert(root, 60);
  
    // Inserting value 80
    insert(root, 80);
  
    // Print the BST
    inorder(root);
    cout << endl;
    preOrder(root);
    cout << endl;
    cout << "PRINTING LEVEL ORDER"<< endl;
    printLevelOrder(root);

    cout << endl;

    cout << "DELETING NODE" << endl;

    root = deleteNode(root, 60);

    inorder(root);

    bool search = iterativeSearch(root, 50);

    if (search) cout << "FOUND " << " " << endl;
    else cout << "NOT FOUND " << " " << endl;

    cout << "+++++++++++++++++++++++++++++++++++++++" << endl;

    int arr[] = {1, 2, 3, 4, 5, 6, 7};
    int n = sizeof(arr) / sizeof(arr[0]);
 
    /* Convert List to BST */
    node *root1 = sortedArrayToBST(arr, 0, n-1);
    cout << "PreOrder Traversal of constructed BST \n";
    preOrder(root1);

    cout << "-------------------------- BST FROM PRE ORDER------------------------" << endl;

    int pre[] = { 10, 5, 1, 7, 40, 50 };
    int size = sizeof(pre) / sizeof(pre[0]);
 
      // Function call
    node* root2 = constructBST(pre, size);
 
    inorder(root2);
  
    cout << "--------------------List to BST-----------------------------------" << endl;

    lnode* head = NULL;
 
    /* Let us create a sorted linked list to test the functions
    Created linked list will be 1->2->3->4->5->6->7 */
    push(&head, 7);
    push(&head, 6);
    push(&head, 5);
    push(&head, 4);
    push(&head, 3);
    push(&head, 2);
    push(&head, 1);

    /* Convert List to BST */
    node *root3 = listToBST(head);
    cout<<"\nPreOrder Traversal of constructed BST ";
    preOrder(root3);

    cout << endl << " ________________ level order to BST_____________" << endl;

    int arr1[] = { 7, 4, 12, 3, 6, 8, 1, 5, 10 };
    int n1 = sizeof(arr1) / sizeof(arr1[0]);
 
    node* root4 = levelOrderBST(arr1, n1);
 
    cout << "Inorder Traversal: ";
    inorder(root4);

    cout << endl << " ------------------------------------ K sm in a BST-------------------------" << endl;

    node* root5 = NULL;
    int keys[] = { 20, 8, 22, 4, 12, 10, 14 };
 
    for (int x : keys)
        root5 = insert(root5, x);
 
    int k = 3;
    printKSmallestBST(root5, k);
    return 0;
}