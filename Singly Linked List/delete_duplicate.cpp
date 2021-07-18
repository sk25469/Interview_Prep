/** Delete duplicate elements in a list **/

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

void deleteDuplicates(Node *head)
{
    Node *curr = head, *nextToNext;

    if (curr == NULL)
        return;

    while (curr->next)
    {
        if (curr->key == curr->next->key)
        {
            nextToNext = curr->next->next;
            free(curr->next);
            curr->next = nextToNext;
        }
        else
            curr = curr->next;
    }
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
    Node *head = NULL;
    pushFront(&head, 3);
    pushFront(&head, 2);
    pushFront(&head, 2);
    pushFront(&head, 1);
    pushFront(&head, 1);

    cout << "Before removing\n";
    printList(head);

    cout << "After removing\n";
    deleteDuplicates(head);
    printList(head);
}