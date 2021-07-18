/** Main approach is to do a post order traversal, calculate current sum as
 * curr = root->data + lefttree_sum + righttree_sum, then return the max of those values **/

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

int maxSumSubTreeUtil(Node *root, int &maxSum)
{

    if (root == NULL)
        return 0;

    int currSum = root->data + maxSumSubTreeUtil(root->left, maxSum) +
                  maxSumSubTreeUtil(root->right, maxSum);

    maxSum = max(currSum, maxSum);

    return currSum;
}

int maxSumSubTree(Node *root)
{
    if (root == NULL)
        return 0;

    int ans = INT32_MIN;

    maxSumSubTreeUtil(root, ans);
    return ans;
}

int main()
{

    Node *root = newNode(-10);
    root->left = newNode(9);
    root->right = newNode(20);
    // root->left->left = newNode(4);
    // root->left->right = newNode(5);
    root->right->left = newNode(15);
    root->right->right = newNode(7);

    cout << maxSumSubTree(root);
}