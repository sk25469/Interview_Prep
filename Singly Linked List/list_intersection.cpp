/** Intersection of 2 sorted lists **/

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

void pushBack(Node **head_ref, int data)
{
    Node *temp = newNode(data);

    Node *lastNode = *head_ref;
    temp->next = NULL;

    // if the head ref is null, it is a empty list, just make the new node as head and return
    if (*head_ref == NULL)
    {
        *head_ref = temp;
        return;
    }
    while (lastNode->next)
        lastNode = lastNode->next;

    lastNode->next = temp;
    return;
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

void pushFront(Node **head_ref, int data)
{
    Node *temp = newNode(data);
    temp->next = *head_ref;

    *head_ref = temp;
}

/** We will traverse the first list until we find the equal element to the second list
 * then we will store the values which are same, then traverse till one of the lists end **/

Node *intersectionOfLists(Node *head1, Node *head2)
{
    if (head1 == NULL || head2 == NULL)
        return NULL;

    Node *intersect = NULL;

    while (head1 && head2)
    {
        if (head1->key == head2->key)
        {
            pushBack(&intersect, head1->key);
            head1 = head1->next;
            head2 = head2->next;
        }
        else if (head1->key < head2->key)
            head1 = head1->next;

        else if (head1->key < head2->key)
            head2 = head2->next;
    }

    return intersect;
}

int main()
{
    Node *head1 = NULL;
    pushFront(&head1, 5);
    pushFront(&head1, 4);
    pushFront(&head1, 3);
    pushFront(&head1, 2);
    pushFront(&head1, 1);

    Node *head2 = NULL;
    pushFront(&head2, 5);
    pushFront(&head2, 3);
    pushFront(&head2, 2);

    printList(head1);
    printList(head2);

    cout << "Intersection\n";
    Node *temp = intersectionOfLists(head1, head2);
    printList(temp);
}