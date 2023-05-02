#include <bits/stdc++.h>

using namespace std;

class Node
{
    public:
    int data;
    Node * next;
};

Node * sortedMerged(Node * a, Node * b)
{
    Node * result = nullptr;

    if (a == nullptr) return b;
    else if (b == nullptr) return a;

    if (a->data <= b->data)
    {
        result = a;
        result->next = sortedMerged(a->next, b);
    }
    else
    {
        result = b;
        result->next = sortedMerged(a, b->next);
    }
    return result;
}

void push(Node** head_ref, int new_data)
{
    /* allocate node */
    Node* new_node = new Node();
 
    /* put in the data */
    new_node->data = new_data;
 
    /* link the old list of the new node */
    new_node->next = (*head_ref);
 
    /* move the head to point to the new node */
    (*head_ref) = new_node;
}

void printList(Node* node)
{
    while (node != NULL) {
        cout << node->data << " ";
        node = node->next;
    }
}
 
/* Driver code*/
int main()
{
    /* Start with the empty list */
    Node* res = NULL;
    Node* a = NULL;
    Node* b = NULL;
 
    /* Let us create two sorted linked lists
    to test the functions
    Created lists, a: 5->10->15, b: 2->3->20 */
    push(&a, 15);
    push(&a, 10);
    push(&a, 5);
 
    push(&b, 20);
    push(&b, 3);
    push(&b, 2);
 
    /* Remove duplicates from linked list */
    res = sortedMerged(a, b);
 
    cout << "Merged Linked List is: \n";
    printList(res);
 
    return 0;
}