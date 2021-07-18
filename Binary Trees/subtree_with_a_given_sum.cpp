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

bool subTreeWithSumUtils(Node *root, int *currentSum, int sum)
{
    if (root == NULL)
    {
        *currentSum = 0;
        return false;
    }

    int leftSum = 0, rightSum = 0;
    /** calculate the left sum, then the right sum of the Node root
     * then assign currentsum = leftsum + rightsum + root->data
     * then check if currentsum == sum **/
    return ((subTreeWithSumUtils(root->left, &leftSum, sum)) ||
            (subTreeWithSumUtils(root->right, &rightSum, sum)) ||
            ((*currentSum = (leftSum + rightSum + root->data)) == sum));
}

bool subTreeWithSum(Node *root, int sum)
{
    int currentSum = 0;
    return subTreeWithSumUtils(root, &currentSum, sum);
}

int main()
{
    Node *root = newNode(8);
    root->left = newNode(5);
    root->right = newNode(4);
    root->left->left = newNode(9);
    root->left->right = newNode(7);
    root->left->right->left = newNode(1);
    root->left->right->right = newNode(12);
    root->left->right->right->right = newNode(2);
    root->right->right = newNode(11);
    root->right->right->left = newNode(3);
    int sum = 22;

    if (subTreeWithSum(root, sum))
        cout << "Found\n";
    else
        cout << "Not found\n";
}