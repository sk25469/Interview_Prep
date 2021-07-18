/*8 Given a sorted list, calculate the no. of triplet with sum = x **/

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

int triplets(Node *head, int sum)
{
    int counter = 0;
    unordered_map<int, Node *> mp; // we will map the node key and value
    // then go through the nodes adding the pair of nodes, then find if x - (key1 + key2) is
    // present in the map

    for (auto ptr = head; ptr != NULL; ptr = ptr->next)
        mp[ptr->data] = ptr;

    for (auto ptr1 = head; ptr1 != NULL; ptr1 = ptr1->next)
    {
        for (auto ptr2 = ptr1->next; ptr2 != NULL; ptr2 = ptr2->next)
        {

            int x = sum - (ptr1->data + ptr2->data);
            if (mp.find(x) != mp.end() && mp[x] != ptr1 && mp[x] != ptr2)
                counter++;
        }
    }

    return (counter / 3);
}

/** There is one more way in O(1) space complexity, we can iterate from back and front
 * for each of the node, and check where the two values match the sum of 2 required **/

int main()
{
    Node *head;

    // pushFront values in sorted order
    pushFront(&head, 9);
    pushFront(&head, 8);
    pushFront(&head, 6);
    pushFront(&head, 5);
    pushFront(&head, 4);
    pushFront(&head, 2);
    pushFront(&head, 1);

    int x = 17;

    cout << "Count = "
         << triplets(head, x);
}