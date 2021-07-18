/** The main idea is to recursively check go through the longest
 * path till leaf in left and right subtree, and return the longest vector,
 * then append the root in the vector and print it*/

#include <bits/stdc++.h>
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

vector<int> longestPath(Node *root)
{
    if (root == NULL)
        return {};

    vector<int> rightVect = longestPath(root->right);
    vector<int> leftVect = longestPath(root->left);

    if (rightVect.size() > leftVect.size())
        rightVect.push_back(root->data);
    else
        leftVect.push_back(root->data);

    return (rightVect > leftVect ? rightVect : leftVect);
}

int main()
{
    Node *root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
    root->left->right->right = newNode(6);

    vector<int> longest = longestPath(root);
    cout << "Longest path of length " << longest.size() << endl;
    cout << "Path -> ";
    cout << longest[longest.size() - 1] << " ";
    for (int i = longest.size() - 2; i >= 0; i--)
        cout << longest[i] << " ";

    cout << endl;
}