/** Doubly linked list **/
#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    Node(){};
    Node *next, *prev;
    int data;
};

Node *newNode(int data)
{
    Node *temp = new Node();
    temp->next = temp->prev = NULL;
    temp->data = data;
    return temp;
}

void pushFront(Node **head_ref, int data)
{
    Node *temp = newNode(data);
    temp->prev = NULL;
    temp->next = *head_ref;

    if (*head_ref)
        (*head_ref)->prev = temp;

    *head_ref = temp;
}

void insertAfter(Node *prevNode, int data)
{

    if (prevNode == NULL)
        return;

    Node *temp = newNode(data);
    temp->next = prevNode->next;
    temp->prev = prevNode;
    prevNode->next = temp;
    if (temp->next)
        temp->next->prev = temp;
}

void insertBefore(Node **head_ref, Node *nextNode, int data)
{
    Node *temp = newNode(data);

    temp->next = nextNode;
    temp->prev = nextNode->prev;
    nextNode->prev = temp;

    if (temp->prev)
        temp->prev->next = temp;
    else
        *head_ref = temp;
}

void deleteNode(Node *node, Node **head_ref)
{

    if (node == NULL || *head_ref == NULL)
        return;

    if (node == *head_ref)
    {
        *head_ref = node->next;
        return;
    }

    if (node->next == NULL)
    {
        node->prev->next = NULL;
        free(node);
        return;
    }

    node->next->prev = node->prev;
    node->prev->next = node->next;
    free(node);
}

void printFrwrd(Node *head)
{
    while (head)
    {
        cout << head->data << " ";
        head = head->next;
    }

    cout << endl;
}

int main()
{
    Node *head = newNode(5);
    pushFront(&head, 4);
    pushFront(&head, 9);

    insertAfter(head->next, 8);
    insertBefore(&head, head->next->next, 10);
    printFrwrd(head);

    deleteNode(head->next, &head);

    printFrwrd(head);
}