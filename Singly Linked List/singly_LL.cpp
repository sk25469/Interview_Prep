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

// push a node at the front of list
/** First set the next of new node to point to the previous head
 * Then move the head ref to point to the new node **/
void pushFront(Node **head_ref, int data)
{
    Node *temp = newNode(data);
    temp->next = *head_ref;

    *head_ref = temp;
}

// this is an O(1)

// Push the node after a given node
/** First create new node, move the next of new node to point to the next of prev node
 * Then make the next of prev node to point to the new node**/
void pushAfter(Node *prev, int data)
{
    Node *temp = newNode(data);
    temp->next = prev->next;

    prev->next = temp;
}

// if the prev node ref is given then it is also O(1)

// push the node at the back of the list
/** First we have to traverse till the end of the linked list from the head ref
 * Then create a new node and make the next of new node null
 * make the next of last node to be the new node **/

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

// Delete a node given the key
/** For deleting a node, we not only have to free the pointers, but also free the memory
 * When we will encounter the node, we will keep track of its prev node,
 * so we can do prev->next = temp->next, and free the node from the list **/

void deleteNode(Node **head_ref, int data)
{
    Node *temp = *head_ref;
    Node *prev = NULL;

    // if the node to be deleted is head
    if (temp != NULL && temp->key == data)
    {
        *head_ref = temp->next;
        delete temp;
        return;
    }

    while (temp && temp->key != data)
    {
        prev = temp;
        temp = temp->next;
    }

    // if the key was not present
    if (temp == NULL)
    {
        cout << "Node not present\n";
        return;
    }

    prev->next = temp->next;
    delete temp;
    return;
}

// Find middle element without calculating the length of the list
/** We can use the concept of slow and fast pointer, fast pointer moves 2 steps
 * while the slow pointer moves 1 step, when fast reaches the end, slow is in the middle **/

void midElement(Node *head)
{
    Node *fast = head;
    Node *slow = head;
    // cout << fast->key << " " << slow->key << endl;

    if (head != NULL)
    {
        while (fast->next != NULL && fast != NULL)
        {
            fast = fast->next->next;
            slow = slow->next;
        }
        cout << "Mid element " << slow->key << endl;
    }
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
    pushFront(&head, 4);

    pushFront(&head, 3);
    pushFront(&head, 2);
    pushFront(&head, 1);
    //pushBack(&head, 5);
    //pushAfter(head->next->next, 9);
    midElement(head);
    //
    printList(head);

    // deleteNode(&head, 5);
    // printList(head);

    // deleteNode(&head, 0);
}
