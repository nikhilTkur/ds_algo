#include <bits/stdc++.h>

using namespace std;

class Node
{
    public:
    int data;
    Node * next;
    Node * prev;
};

void push(Node ** head, int new_data)
{
    Node * new_node = new Node();

    new_node->data = new_data;

    new_node->prev = nullptr;
    new_node->next = *head;
    if (*head)
    {
        (*head)->prev = new_node;
    }
    *head = new_node;
}

void reverse(Node** head)
{
    Node * temp = nullptr;
    Node * current = *head;

    while (current != nullptr)
    {
        temp = current->prev;
        current->prev = current->next;
        current->next = temp;
        current = current->prev;
    }

    if (temp) (*head) = temp->prev;
}
void printList(Node* node)
{
    while (node != NULL) {
        cout << node->data << " ";
        node = node->next;
    }
}

int main()
{
    /* Start with the empty list */
    Node* head = NULL;
 
    /* Let us create a sorted linked list to test the
    functions Created linked list will be 10->8->4->2 */
    push(&head, 2);
    push(&head, 4);
    push(&head, 8);
    push(&head, 10);
 
    cout << "Original Linked list" << endl;
    printList(head);
 
    // Function call
    reverse(&head);
 
    cout << "\nReversed Linked list" << endl;
    printList(head);
 
    return 0;
}
