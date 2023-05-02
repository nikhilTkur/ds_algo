#include <bits/stdc++.h>

using namespace std;

class Node
{
    public:
    int data;
    Node * next;
};

void printList(struct Node* node)
{
    while (node != NULL) {
        cout << " " << node->data;
        node = node->next;
    }
}

void push(struct Node** head_ref, int new_data)
{
    Node* new_node = new Node();
 
    new_node->data = new_data;
 
    new_node->next = (*head_ref);
 
    (*head_ref) = new_node;
}

Node * intersection(Node * n1, Node * n2)
{
    if (n1 == nullptr || n2 == nullptr) return nullptr;
    if (n1->data < n2->data)
    {
        return intersection(n1->next , n2);
    }
    else if (n1->data > n2->data)
    {
        return intersection(n1, n2->next);
    }
    else
    {
        Node * temp = new Node();
        temp->data = n1->data;
        temp->next = intersection(n1->next , n2->next);
        return temp;
    }
}

Node * intersectReferences(Node * n1, Node * n2)
{
    Node * result = nullptr;
    Node ** resref = &result;
    while (n1 != nullptr && n2 != nullptr)
    {
        if (n1->data == n2->data)
        {
            push(resref, n1->data);
            resref = &((*resref)->next);
            n1 = n1->next;
            n2 = n2->next;
        }
        else if (n1->data < n2->data)
            n1 = n1->next; /* advance the smaller list */
        else
            n2 = n2->next;
    }
    return result;
}

int main()
{
     
    /* Start with the empty lists */
    struct Node* a = NULL;
    struct Node* b = NULL;
    struct Node* intersect = NULL;
 
    /* Let us create the first sorted
      linked list to test the functions
     Created linked list will be
      1->2->3->4->5->6 */
    push(&a, 6);
    push(&a, 5);
    push(&a, 4);
    push(&a, 3);
    push(&a, 2);
    push(&a, 1);
 
    /* Let us create the second sorted linked list
     Created linked list will be 2->4->6->8 */
    push(&b, 8);
    push(&b, 6);
    push(&b, 4);
    push(&b, 2);
 
    /* Find the intersection two linked lists */
    //intersect = intersection(a, b);

    Node * intersect2 = intersectReferences(a,b);
 
    cout << "\n Linked list containing "
         << "common items of a & b \n ";
    printList(intersect2);
 
    return 0;
}