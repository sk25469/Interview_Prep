#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    Node(){};
    int key;
    Node *next;
};

Node *newNode(int data)
{
    Node *node = new Node();
    node->key = data;
    node->next = NULL;
    return node;
}

/** to reverse the pointers, we store prev, curr and next pointers
 * before going to the next 
 * 1. next = curr->next,
 * 2. curr->next = prev,
 * 3. prev = curr,
 * 4. curr = next **/

void reverse(Node **head_ref)
{
    Node *curr = *head_ref, *prev = NULL, *next = NULL;
    while (curr)
    {

        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }

    *head_ref = prev;
}

void pushFront(Node **head_ref, int data)
{
    Node *temp = newNode(data);
    temp->next = *head_ref;

    *head_ref = temp;
}

void printList(Node *head)
{
    while (head)
    {
        cout << head->key << " ";
        head = head->next;
    }
    cout << endl;
}

int main()
{
    Node *head = newNode(2);
    pushFront(&head, 5);
    pushFront(&head, 4);
    pushFront(&head, 4);
    pushFront(&head, 1);

    cout << "Before reversing\n";
    printList(head);

    cout << "After reversing\n";
    reverse(&head);

    printList(head);
}