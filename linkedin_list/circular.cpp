#include <bits/stdc++.h>

using namespace std;

class Node 
{
    public:
    int data;
    Node * next;
};

void push (Node ** head, int data)
{
    Node * new_node = new Node();
    Node * temp = *head;

    new_node->data = data;
    new_node->next = *head;

    if (*head)
    {
        while (temp->next != *head)
        {
            temp = temp->next;
        }

        temp->next = new_node;
    }
    else
    {
        new_node->next = new_node;
    }

    *head = new_node;
}/* Function to print nodes in
a given Circular linked list */
void printList(Node *head)
{
    Node *temp = head;
    if (head != NULL)
    {
        do
        {
            cout << temp->data << " ";
            temp = temp->next;
        }
        while (temp != head);
    }
}
 
/* Driver program to test above functions */
int main()
{
    /* Initialize lists as empty */
    Node *head = NULL;
 
    /* Created linked list will be 11->2->56->12 */
    push(&head, 12);
    push(&head, 56);
    push(&head, 2);
    push(&head, 11);
 
    cout << "Contents of Circular Linked List\n ";
    printList(head);
 
    return 0;
}