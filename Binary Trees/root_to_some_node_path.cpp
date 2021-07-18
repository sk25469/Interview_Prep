/** Main thing here is to push the current node and check if the required node
 * exists in left or right subtree, if exists return true and push the values in the array,
 * if we cant find return false, and pop the current node **/

#include <bits/stdc++.h>
#include <queue>
#include <vector>
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

bool rootToNode(Node *root, vector<int> &ar, int x)
{
    if (root == NULL)
        return false;

    ar.push_back(root->data);

    if (root->data == x)
        return true;

    if (rootToNode(root->left, ar, x) || rootToNode(root->right, ar, x))
        return true;

    ar.pop_back();
    return false;
}

void printRootToNode(Node *root, int node)
{
    vector<int> ar;

    if (rootToNode(root, ar, node))
    {
        for (int i = 0; i < ar.size(); i++)
            cout << ar[i] << " ";
    }
    else
        cout << "No path\n";
}

int main()
{
    Node *root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
    root->right->left = newNode(6);
    root->right->right = newNode(7);

    int x = 5;
    printRootToNode(root, x);
}