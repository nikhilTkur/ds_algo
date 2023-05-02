#include <bits/stdc++.h>

using namespace std;

class Node
{
    public:

    int data;
    Node * next;
    Node(int d) {data = d;}
};

bool isPalNewUtil(Node ** left, Node * right)
{
    if (right == nullptr) return true;

    if (!isPalNewUtil(left, right->next))
    {
        return false;
    }

    bool isp = ((*left)->data == right->data);

    *left = (*left)->next;

    return isp;
}

bool isPalNew(Node ** head)
{
    return isPalNewUtil(head, *head);
}

bool isPalindrome(Node * head)
{
    Node * p = head;

    stack<int> s;

    while (p != nullptr)
    {
        s.push(p->data);
        p = p->next;
    }

    while (head != nullptr)
    {
        int i = s.top();
        s.pop();

        if (head->data != i)
        {
            return false;
        }

        head = head->next;
    }
    return true;
}

// Driver Code
int main()
{
 
    // Addition of linked list
    Node one = Node(1);
    Node two = Node(2);
    Node three = Node(3);
    Node four = Node(2);
    Node five = Node(1);
 
    // Initialize the next pointer
    // of every current pointer
    five.next = NULL;
    one.next = &two;
    two.next = &three;
    three.next = &four;
    four.next = &five;
    Node* temp = &one;
 
    // Call function to check palindrome or not
    int result = isPalindrome(&one);
 
    if (result == 1)
        cout << "isPalindrome is true\n";
    else
        cout << "isPalindrome is false\n";
 
    return 0;
}