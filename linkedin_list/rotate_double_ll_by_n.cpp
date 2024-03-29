#include <bits/stdc++.h>

using namespace std;

class Node
{
    public:
    int data;
    Node * next;
    Node * prev;

    Node(int data)
    {
        this->data = data;
        prev = nullptr;
        next = nullptr;
    }
};

void insertAtHead(Node * &head, int data)
{
    Node * n = new Node (data);
    if (head == nullptr)
    {
        head = n;
        return;
    }

    n->next = head;
    head->prev = n;
    head = n;
    return;
}

void insertAtTail(Node * &head, int data)
{
    if (head == nullptr)
    {
        insertAtHead(head, data);
        return;
    }

    Node * temp = head;

    while (temp->next)
    {
        temp = temp->next;
    }

    Node * n = new Node(data);

    temp->next = n;
    n->prev = temp;
    return;
}

void display(Node * head)
{
    while (head)
    {
        cout << head->data << " ";
        head = head->next;
    }
}

void rotateByN(Node * &head, int pos)
{
    if (pos == 0)
    {
        return;
    }

    Node * temp = head;

    while (temp->next)
    {
        temp = temp->next;
    }

    temp->next = head;
    head->prev = temp;

    int count = 1;

    while (count <= pos)
    {
        head = head->next;
        temp = temp->next;
        count++;
    }

    temp->next = nullptr;
    head->prev = nullptr;
}

int main()
{
    Node* head=NULL;
    insertAtTail(head,'a');
    insertAtTail(head,'b');
    insertAtTail(head,'c');
    insertAtTail(head,'d');
    insertAtTail(head,'e');
 
    int n=2;
    cout << "Given linked list \n";
    display(head);
    rotateByN(head,n);
    cout << "\nRotated Linked list \n";
    display(head);
    cout << "\n\n";
 
    return 0;
}