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

bool printPath(Node *root,
               Node *target_leaf)
{
    // base case
    if (root == NULL)
        return false;

    // return true if this node is the target_leaf
    // or target leaf is present in one of its
    // descendants
    if (root == target_leaf || printPath(root->left, target_leaf) ||
        printPath(root->right, target_leaf))
    {
        cout << root->data << " ";
        return true;
    }

    return false;
}

// This function Sets the target_leaf_ref to refer
// the leaf node of the maximum path sum. Also,
// returns the max_sum using max_sum_ref
void getTargetLeaf(Node *root, int *max_sum_ref,
                   int curr_sum, Node **target_leaf_ref)
{
    if (root == NULL)
        return;

    // Update current sum to hold sum of nodes on path
    // from root to this node
    curr_sum = curr_sum + root->data;

    // If this is a leaf node and path to this node has
    // maximum sum so far, then make this node target_leaf
    if (root->left == NULL && root->right == NULL)
    {
        if (curr_sum > *max_sum_ref)
        {
            *max_sum_ref = curr_sum;
            *target_leaf_ref = root;
        }
    }

    // If this is not a leaf node, then recur down
    // to find the target_leaf
    getTargetLeaf(root->left, max_sum_ref, curr_sum,
                  target_leaf_ref);
    getTargetLeaf(root->right, max_sum_ref, curr_sum,
                  target_leaf_ref);
}

// Returns the maximum sum and prints the nodes on max
// sum path
int maxSumPath(Node *root)
{
    // base case
    if (root == NULL)
        return 0;

    Node *target_leaf;
    int max_sum = INT_MIN;

    // find the target leaf and maximum sum
    getTargetLeaf(root, &max_sum, 0, &target_leaf);

    // print the path from root to the target leaf
    printPath(root, target_leaf);

    return max_sum; // return maximum sum
}

int main()
{
    Node *root = NULL;

    /* Constructing tree given in the above figure */
    root = newNode(10);
    root->left = newNode(-2);
    root->right = newNode(7);
    root->left->left = newNode(8);
    root->left->right = newNode(-4);

    cout << "Following are the nodes on the maximum "
            "sum path \n";
    int sum = maxSumPath(root);
    cout << "\nSum of the nodes is " << sum;
    return 0;
}