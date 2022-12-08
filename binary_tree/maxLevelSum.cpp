#include <iostream>
#include "binary_tree.h"
#include <queue>
#include <algorithm>

using namespace std;

int maxLevelSum(Node * root)
{
    if (!root) return 0;

    queue<Node *> q;
    q.push(root);
    int sum = 0;

    while(!q.empty())
    {
        int count = q.size();
        int levelSum = 0;
        while (count--)
        {
            Node * temp = q.front();
            levelSum += temp->data;
            q.pop();

            if (temp->left) q.push(temp->left);
            if (temp->right) q.push(temp->right);
        }

        sum = max(sum, levelSum);
    }

    return sum;
}

int main()
{
    Node* root = createNode(1);
    root->left = createNode(2);
    root->right = createNode(3);
    root->left->left = createNode(4);
    root->left->right = createNode(5);
    root->right->right = createNode(8);
    root->right->right->left = createNode(6);
    root->right->right->right = createNode(7);
  
    /*   Constructed Binary tree is:
                 1
               /   \
             2      3
           /  \      \
          4    5      8
                    /   \
                   6     7    */
    cout << "Maximum level sum is " << maxLevelSum(root)
         << endl;
    return 0;
}