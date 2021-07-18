/** The main idea here is to do a level order transversal and check if we hit a leaf,
 * we will keep the visited nodes in a map and then print the path using map **/

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

vector<int> minPath; // to store the path in a vector

void storePath(int data, unordered_map<int, int> parent)
{
    if (parent[data] == data)
        return; // if parent of the data is the same that means its a root

    storePath(parent[data], parent);

    minPath.push_back(parent[data]);
}

void checkLeafNode(Node *root)
{
    queue<Node *> q;
    q.push(root);

    int leafData = -1;
    unordered_map<int, int> parent;
    parent[root->data] = root->data;

    Node *temp = NULL;

    while (!q.empty())
    {
        temp = q.front();
        q.pop();

        // if we find the leaf node then we just break and print the path
        if (temp->left == NULL && temp->right == NULL)
        {
            leafData = temp->data;
            break;
        }
        else
        {
            if (temp->left)
            {
                q.push(temp->left);

                // Set temp's left node's parent as temp
                parent[temp->left->data] = temp->data;
            }

            // If current node has right
            // child, push in the queue
            if (temp->right)
            {
                q.push(temp->right);

                // Set temp's right node's parent
                // as temp
                parent[temp->right->data] = temp->data;
            }
        }
    }

    storePath(leafData, parent);

    minPath.push_back(leafData);
}

int main()
{
    Node *root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->right->left = newNode(5);
    root->right->right = newNode(7);
    root->left->left->left = newNode(10);
    root->left->left->right = newNode(11);
    root->right->right->left = newNode(8);

    checkLeafNode(root);
    for (auto x : minPath)
        cout << x << " ";
    cout << "\n";

    return 0;
}