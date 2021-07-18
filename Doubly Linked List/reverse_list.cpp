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

/** To reverse a list, we create a new head pointer, and push the nodes as we traverse the original
 * node, and then we print the new node, it will be in reverse to the actual node **/

// function to insert a node at the beginging
// of the Doubly Linked List
void push(Node **head_ref, Node *new_node)
{
    // since we are adding at the beginning,
    // prev is always NULL
    new_node->prev = NULL;

    // link the old list off the new node
    new_node->next = (*head_ref);

    // change prev of head node to new node
    if ((*head_ref) != NULL)
        (*head_ref)->prev = new_node;

    // move the head to point to the new node
    (*head_ref) = new_node;
}

// function to reverse a doubly linked list
void reverseList(Node **head_ref)
{
    // if list is empty or it contains
    // a single node only
    if (!(*head_ref) || !((*head_ref)->next))
        return;

    Node *new_head = NULL;
    Node *curr = *head_ref, *next;

    while (curr != NULL)
    {

        // get pointer to next node
        next = curr->next;

        // push 'curr' node at the beginning of the
        // list with starting with 'new_head'
        push(&new_head, curr);

        // update 'curr'
        curr = next;
    }

    // update 'head_ref'
    *head_ref = new_head;
}

void printList(Node *head)
{
    while (head != NULL)
    {
        cout << head->data << " ";
        head = head->next;
    }
}

int main()
{
    Node *head = NULL;

    // Create doubly linked: 10<->8<->4<->2 */
    // push(&head, getNode(2));
    // push(&head, getNode(4));
    // push(&head, getNode(8));
    // push(&head, getNode(10));

    push(&head, newNode(2));
    push(&head, newNode(4));
    push(&head, newNode(8));
    push(&head, newNode(10));
    push(&head, newNode(1));

    cout << "Original list: ";
    printList(head);

    // Reverse doubly linked list
    reverseList(&head);

    cout << "\nReversed list: ";
    printList(head);
}