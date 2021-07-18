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

int maxPathSumUtils(Node *root, int &res)
{

    if (root == NULL)
        return 0;

    if (!root->left && !root->right)
        return root->data;

    // variables to store the root to leaf sum in left and right subtree
    int lSum = maxPathSumUtils(root->left, res);
    int rSum = maxPathSumUtils(root->right, res);

    // if the node is not a leaf, we need to update the result
    // to be the max of current res and lsum + rsum + data
    if (root->left && root->right)
    {
        res = max(res, lSum + rSum + root->data);

        return max(lSum, rSum) + root->data;
    }

    // if one of the sub tree is null
    // we return the sum till the other

    return (!root->left) ? rSum + root->data : lSum + root->data; // ????
}

int maxPathSum(Node *root)
{

    int res = INT_MIN;
    int value = maxPathSumUtils(root, res);
    // If one side of root is empty, then function should return minus infinite

    return max(res, value);
}

int main()
{
    Node *root = newNode(-15);
    root->left = newNode(5);
    root->right = newNode(6);
    root->left->left = newNode(-8);
    root->left->right = newNode(1);
    root->left->left->left = newNode(2);
    root->left->left->right = newNode(6);
    root->right->left = newNode(3);
    root->right->right = newNode(9);
    root->right->right->right = newNode(0);
    root->right->right->right->left = newNode(4);
    root->right->right->right->right = newNode(-1);
    root->right->right->right->right->left = newNode(10);
    cout << "Max pathSum of the given binary tree is "
         << maxPathSum(root);
}