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

/** For boundry traversal, we need 3 steps - 
 * 1. Print all the left nodes in top down manner
 * 2. Print all the left subtree leaves, then the right subtree leaves
 * 3. Print all the right nodes in bottom up manner 
 * Note - We need to be careful of the left and right nodes which are leaves because we
 * have already considered them in step 2 **/

void printLeaves(Node *root)
{
    if (root == NULL)
        return;

    printLeaves(root->left);

    if (!(root->left) && !(root->right))
        cout << root->data << " ";

    printLeaves(root->right);
}

void printBoundryLeft(Node *root)
{
    /** for top bottom first we print the data, then go to the left/right child **/
    if (root == NULL)
        return;

    if (root->left)
    {
        cout << root->data << " ";
        printBoundryLeft(root->left);
    }

    else if (root->right)
    {
        cout << root->data << " ";
        printBoundryLeft(root->right);
    }

    /** else if root doesn't have a left and right child that means it is a leaf
     * and we have already taken care of the leaf in other function **/
}

void printBoundryRight(Node *root)
{
    /** for top bottom first we print the data, then go to the left/right child **/
    if (root == NULL)
        return;

    if (root->right)
    {
        printBoundryLeft(root->right);
        cout << root->data << " ";
    }

    else if (root->left)
    {
        printBoundryLeft(root->left);
        cout << root->data << " ";
    }

    /** else if root doesn't have a left and right child that means it is a leaf
     * and we have already taken care of the leaf in other function **/
}

void printBoundry(Node *root)
{
    if (root == NULL)
        return;
    cout << root->data << " ";
    printBoundryLeft(root->left);

    printLeaves(root->left);
    printLeaves(root->right);

    printBoundryRight(root->right);
}

int main()
{
    Node *root = newNode(20);
    root->left = newNode(8);
    root->left->left = newNode(4);
    root->left->right = newNode(12);
    root->left->right->left = newNode(10);
    root->left->right->right = newNode(14);
    root->right = newNode(22);
    root->right->right = newNode(25);

    cout << "Boundry Traversal\n";
    printBoundry(root);
}