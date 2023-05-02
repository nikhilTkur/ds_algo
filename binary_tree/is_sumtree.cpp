// #include <iostream>
// #include "binary_tree.h"

// int sum(Node * root)
// {
//     if (root == nullptr)
//     {
//         return 0;
//     }

//     else return sum(root->left) + root->data + sum(root->right);
// }

// bool isSumTree (Node * root)
// {
//     if (root == nullptr || (root->left == nullptr && root->right == nullptr))
//     {
//         return true;
//     }

//     int leftSum = sum (root->left);
//     int rightSum = sum (root->right);

//     if (root->data == leftSum + rightSum
//          && isSumTree (root->left)
//          && isSumTree (root->right))
//     {
//         return true;    
//     }

//     return false;
// }

// int main()
// {
//     Node * root = createNode(26);
//     root->left = createNode(10);
//     root->right = createNode(3);
//     root->left->left = createNode(4);
//     root->left->right = createNode(6);
//     root->right->right = createNode(3);
     
//     if (isSumTree(root))
//         std::cout << "The given tree is a SumTree ";
//     else
//         std::cout << "The given tree is not a SumTree ";
//      return 0;
// }