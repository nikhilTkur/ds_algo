#include<bits/stdc++.h>
using namespace std;

class Node
{
    public:
    char data;
    Node * next;
};

void reverse(Node ** head)
{
    Node * prev = nullptr;
    Node * current = *head;
    Node * next;

    while (current != nullptr)
    {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }

    *head = prev;
}

bool compareLists(Node * head1, Node * head2)
{
    Node * temp1 = head1;
    Node * temp2 = head2;

    while (temp1 && temp2)
    {
        if (temp1->data != temp2->data)
        {
            return false;
        }

        temp1 = temp1->next;
        temp2 = temp2->next;
    }

    if (temp1 == nullptr && temp2 == nullptr)
    {
        return true;
    }

    return false;
}

void push (Node ** head, char data)
{
    Node * new_node = new Node();
    new_node->data = data;
    new_node->next = *head;

    *head = new_node;
}

void printList(struct Node* ptr)
{
    while (ptr != NULL) {
        cout << ptr->data << "->";
        ptr = ptr->next;
    }
    cout << "NULL"
         << "\n";
}

bool isPalindromeWithReversing(Node * head)
{
    Node * slow_p = head , *fast_p = head, *prev_of_slow_p = head, *second_half;

    Node * mid_node = nullptr;
    bool result = true;

    if (head && head->next)
    {
        while (fast_p && fast_p->next)
        {
            fast_p = fast_p->next->next;
            prev_of_slow_p = slow_p;
            slow_p = slow_p->next;
        }

        if (fast_p != nullptr) // odd size list
        {
            mid_node = slow_p;
            slow_p = slow_p->next;
        }

        prev_of_slow_p->next = nullptr;
        second_half = slow_p;

        reverse(&second_half);

        result = compareLists(head, second_half);

        reverse(&second_half);

        if (mid_node)
        {
            prev_of_slow_p->next = mid_node;
            mid_node->next = second_half;
        }
        else
        {
            prev_of_slow_p->next = second_half;
        }

    }

    return result;
}

// Driver code
int main()
{
 
    // Start with the empty list
    struct Node* head = NULL;
    char str[] = "abacaba";
    int i;
 
    for (i = 0; str[i] != '\0'; i++) {
        push(&head, str[i]);
    }
    isPalindromeWithReversing(head) ? cout << "Is Palindrome"
                              << "\n\n"
                       : cout << "Not Palindrome"
                              << "\n\n";
    return 0;
}