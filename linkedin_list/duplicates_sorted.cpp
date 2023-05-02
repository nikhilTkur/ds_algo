#include <bits/stdc++.h>

using namespace std;

class Node
{
    public:
    int data;
    Node * next;
};

void removeDuplicatesInSorted(Node * head)
{
    Node * current = head;
    Node * next;

    while (current->next != nullptr)
    {
        if (current->data == current->next->data)
        {
            // duplicate -> remove it
            next = current->next->next;
            free(current->next);
            current->next = next;
        }
        else
        {
            current = current->next;
        }
    }
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

void printList(Node *node)
{
    while (node!=NULL)
    {
        cout<<" "<<node->data;
        node = node->next;
    }
}
 
/* Driver program to test above functions*/
int main()
{
    /* Start with the empty list */
    Node* head = NULL;
     
    /* Let us create a sorted linked list to test the functions
    Created linked list will be 11->11->11->13->13->20 */
    push(&head, 20);
    push(&head, 13);
    push(&head, 13);
    push(&head, 11);
    push(&head, 11);
    push(&head, 11);                                    
 
    cout<<"Linked list before duplicate removal " << endl;
    printList(head);
 
    /* Remove duplicates from linked list */
    removeDuplicatesInSorted(head);
 
    cout<<"\nLinked list after duplicate removal "<< endl;    
    printList(head);            
     
    return 0;
}