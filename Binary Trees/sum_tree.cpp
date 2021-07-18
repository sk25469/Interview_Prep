#include <bits/stdc++.h>
#include <queue>
using namespace std;

class Node
{
public:
    Node(){};
    int data;
    Node *left, *right;
};

Node *newNode(int data)
{
    Node *node = new Node();
    node->data = data;
    node->left = node->right = NULL;
    return node;
}

/** A sum tree is such that each node is the sum of its right and left subtree
 * Then the leaf nodes are set as 0 **/

// Actually this function also returns the sum of all the nodes
int nodeToSum(Node *root)
{
    if (root == NULL)
        return 0;

    // store the old value in a variable
    int old = root->data;

    // store the left and right subtree sum and update the root data
    root->data = nodeToSum(root->left) + nodeToSum(root->right);

    return old + root->data;
}

void printInorder(Node *Node)
{
    if (Node == NULL)
        return;
    printInorder(Node->left);
    cout << " " << Node->data;
    printInorder(Node->right);
}

int main()
{
    Node *root = NULL;

    /* Constructing tree given in the above figure */
    root = newNode(10);
    root->left = newNode(-2);
    root->right = newNode(6);
    root->left->left = newNode(8);
    root->left->right = newNode(-4);
    root->right->left = newNode(7);
    root->right->right = newNode(5);

    int x = nodeToSum(root); // sum of all the nodes
    cout << x << endl;
    cout << "SumTree \n";
    printInorder(root);
}