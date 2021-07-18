#include <bits/stdc++.h>
#include <vector>
#include <map>
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

/** The main idea behind diagonal traversal is to use a map to store the vertical
 * distance from the root slope line, and map that distance with the vector containing
 * all those elements on the slope **/

void printDiagonalUtil(Node *root, int d, map<int, vector<int>> &diagonal)
{
    if (!root)
        return;

    diagonal[d].push_back(root->data);

    // if there is a right node, the slope doesn't change, else it increases by one
    printDiagonalUtil(root->left, d + 1, diagonal);

    printDiagonalUtil(root->right, d, diagonal);
}

void printDiagonalRec(Node *root)
{
    map<int, vector<int>> diagonal;
    printDiagonalUtil(root, 0, diagonal);

    cout << "Map based recursive Diagonal Traversal \n";
    for (auto x : diagonal)
    {
        vector<int> res = x.second;
        for (auto t : res)
            cout << t << " ";
        cout << endl;
    }
}

/** This recursive method takes O(nlogn) time, we can optimize it further if we use a queue
 * and make it a O(n) **/

vector<vector<int>> result;
void diagonalPrint(Node *root)
{
    if (root == NULL)
        return;

    queue<Node *> q;
    q.push(root);

    while (!q.empty())
    {
        int size = q.size();
        vector<int> answer;

        while (size--)
        {
            Node *temp = q.front();
            q.pop();

            // traversing each component;
            while (temp)
            {
                answer.push_back(temp->data);

                if (temp->left)
                    q.push(temp->left); /** we are only interested in the left child
                because the right child is on the same level **/

                temp = temp->right;
            }
        }
        result.push_back(answer);
    }
}

/** This will take O(n) as each node is traversed max 2 times **/

int main()
{
    Node *root = newNode(8);
    root->left = newNode(3);
    root->right = newNode(10);
    root->left->left = newNode(1);
    root->left->right = newNode(6);
    root->right->right = newNode(14);
    root->right->right->left = newNode(13);
    root->left->right->left = newNode(4);
    root->left->right->right = newNode(7);

    printDiagonalRec(root);

    diagonalPrint(root);
    cout << "Queue based iterative Diagonal Traversal\n";
    for (int i = 0; i < result.size(); i++)
    {
        for (int j = 0; j < result[i].size(); j++)
            cout << result[i][j] << " ";
        cout << endl;
    }
}