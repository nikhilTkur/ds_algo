#include <bits/stdc++.h>

using namespace std;;
class Node 
{
    public:
    int data;
    Node * next;
};

void push(Node ** head, int data)
{
    Node * new_node = new Node ();

    new_node->data = data;
    new_node->next = *head;
    Node * temp = *head;
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
}

void traverse(struct Node* head)
{
    struct Node* p;
 
    // If list is empty, return.
    if (head == NULL) {
        cout << "List is empty." << endl;
        return;
    }
 
    // Pointing to first Node of the list.
    p = head;
 
    // Traversing the list.
    do {
        cout << p->data << " ";
        p = p->next;
 
    } while (p != head);
}

Node * exchangeNodes(Node * head)
{
    if (head->next->next == head)
    {
        head = head->next;
        return head;
    }

    Node * temp = head;

    while (temp->next->next != head)
    {
        temp = temp->next;
    }

    temp->next->next = head->next;
    head->next = temp->next;

    temp->next = head;
    head = head->next;

    return head;
}

int main()
{
    int i;
    struct Node* head = NULL;
    push(&head, 6);
 
    for (i = 5; i > 0; i--)
        push(&head, i);
    cout << "List Before: ";
    traverse(head);
    cout << endl;
 
    cout << "List After: ";
    head = exchangeNodes(head);
    traverse(head);
 
    return 0;
}
