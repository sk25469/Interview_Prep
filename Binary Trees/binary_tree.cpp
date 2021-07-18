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

// creating a binary tree with an array of integers in level order like this
/**       
 * arr[7] = [1,2,3,4,5,6,7]
          1
        /  \
       2    3
      / \  / \
     4   5 6  7
     **/

// if the parent is at position i in the array, left child is at 2*i+1, right is at 2*i+2;

Node *makeTree(int ar[], Node *root, int i, int n)
{
    if (i < n)
    {
        // first we make the root of the tree as ar[i];
        Node *tmp = newNode(ar[i]);
        root = tmp;

        root->left = makeTree(ar, root->left, 2 * i + 1, n);
        root->right = makeTree(ar, root->right, 2 * i + 2, n);
    }

    return root;
}

// Iterative method for level order transveral
void printLevelOrder(Node *root)
{
    // Base Case
    if (root == NULL)
        return;

    // Create an empty queue for level order traversal
    queue<Node *> q;

    // Enqueue Root and initialize height
    q.push(root);

    while (q.empty())
    {
        // Print front of queue and remove it from queue
        Node *node = q.front();
        cout << node->data << " ";
        q.pop();

        /* Enqueue left child */
        if (node->left != NULL)
            q.push(node->left);

        /*Enqueue right child */
        if (node->right != NULL)
            q.push(node->right);
    }
    cout << endl;
}

void printInOrder(Node *root)
{
    if (root != NULL)
    {
        printInOrder(root->left);
        cout << root->data << " ";
        printInOrder(root->right);
    }
}

// in reverse, just reverse the whole operations
void reverseInOrder(Node *root)
{
    if (root != NULL)
    {
        reverseInOrder(root->right);
        cout << root->data << " ";
        reverseInOrder(root->left);
    }
}

/** Inorder iterative can be done by using a stack and pushing all the left nodes first,
 * then we will reach the left most leaf node, then we pop the stack and push the right node
 * of the current node and repeat the above process **/
void inorderIterative(Node *root)
{
    stack<Node *> st;
    Node *curr = root;

    while (curr || !st.empty())
    {
        while (curr)
        {
            // we will push the value first, then move to the next left node
            st.push(curr);
            curr = curr->left;
        }
        // after this loop, we will reach the leftmost leaf
        curr = st.top();
        st.pop();

        cout << curr->data << " ";
        curr = curr->right;
    }
}

void printPreOrder(Node *root)
{
    if (root != NULL)
    {
        cout << root->data << " ";
        printInOrder(root->left);
        printInOrder(root->right);
    }
}

void printPostOrder(Node *root)
{
    if (root != NULL)
    {

        printInOrder(root->left);
        printInOrder(root->right);
        cout << root->data << " ";
    }
}

// Iterative traversal of trees
void iterativePreOrder(Node *root)
{
    if (root == NULL)
        return;
    stack<Node *> st;
    st.push(root);
    /** Note that we are using stack, and the it is LIFO, hence we have to do the operation in reverse
     * of that of recursive method **/

    while (!st.empty())
    {
        Node *node = st.top();
        cout << node->data << " ";
        st.pop();

        // we are doing right and left because we are using stack
        if (node->right)
            st.push(node->right);
        if (node->left)
            st.push(node->left);
    }
}

void postOrderIterative(Node *root)
{
    if (root == NULL)
        return;

    // Create two stacks
    stack<Node *> s1, s2;

    // push root to first stack
    s1.push(root);
    Node *node;

    // Run while first stack is not empty
    while (!s1.empty())
    {
        // Pop an item from s1 and push it to s2
        node = s1.top();
        s1.pop();
        s2.push(node);

        // Push left and right children
        // of removed item to s1
        if (node->left)
            s1.push(node->left);
        if (node->right)
            s1.push(node->right);
    }

    // Print all elements of second stack
    while (!s2.empty())
    {
        node = s2.top();
        s2.pop();
        cout << node->data << " ";
    }
}

// Insertion in binary tree -> we find if there is no left or right child of a node, then
// we insert the new node on either of them
Node *insertNode(Node *root, int key)
{

    if (root == NULL)
    {
        root = newNode(key);
        return root;
    }

    queue<Node *> q;
    q.push(root);

    while (!q.empty())
    {
        Node *temp = q.front();
        q.pop();

        if (temp->left != NULL)
            q.push(temp->left);
        else
        {
            temp->left = newNode(key);
            return root;
        }

        if (temp->right != NULL)
            q.push(temp->right);
        else
        {
            temp->right = newNode(key);
            return root;
        }
    }

    return root;
}

void deleteDeepest(Node *root,
                   Node *d_node)
{
    queue<Node *> q;
    q.push(root);

    // Do level order traversal until last node
    Node *temp;
    while (!q.empty())
    {
        temp = q.front();
        q.pop();
        if (temp == d_node)
        {
            temp = NULL;
            delete (d_node);
            return;
        }
        if (temp->right)
        {
            if (temp->right == d_node)
            {
                temp->right = NULL;
                delete (d_node);
                return;
            }
            else
                q.push(temp->right);
        }

        if (temp->left)
        {
            if (temp->left == d_node)
            {
                temp->left = NULL;
                delete (d_node);
                return;
            }
            else
                q.push(temp->left);
        }
    }
}

/* function to delete element in binary tree */
Node *deletion(Node *root, int key)
{
    if (root == NULL)
        return NULL;

    if (root->left == NULL && root->right == NULL)
    {
        if (root->data == key)
            return NULL;
        else
            return root;
    }

    queue<Node *> q;
    q.push(root);

    Node *temp;
    Node *key_node = NULL;

    // Do level order traversal to find deepest
    // node(temp) and node to be deleted (key_node)
    while (!q.empty())
    {
        temp = q.front();
        q.pop();

        if (temp->data == key)
            key_node = temp;

        if (temp->left)
            q.push(temp->left);

        if (temp->right)
            q.push(temp->right);
    }

    if (key_node != NULL)
    {
        int x = temp->data;
        deleteDeepest(root, temp); // here root is the root from which we will find the deepest
                                   // node and temp is the node to be deleted
        key_node->data = x;
    }
    return root;
}

/** BFS - Breadth first traversal or Level Order Transveral can be done by queue
 *  DFS - Depth first transveral has 3 types
 *  1. Inorder(LDR)   2. Preorder(DLR)   3. Postorder(LRD)  **/

int treeHeightandSize(Node *root, int &size)
{

    if (root == NULL)
        return 0;
    int lHeight = treeHeightandSize(root->left, size);
    int rHeight = treeHeightandSize(root->right, size);
    size++;

    return max(lHeight, rHeight) + 1;
}

/** To do reverse level order we can do 2 things
 * 1. We can make a recursive call from the last level and then go upward in a for loop,this will
 * take a max of O(n*n) time for a skewed tree
 * 2. Instead of that, we can make use of stack and queue to do a normal level order traversal,
 * but instead of printing the node, we will store it in a stack and later print the stack such that 
 * it will give a reverse level order traversal **/

void reverseLevelOrder(Node *root)
{
    stack<Node *> s;
    queue<Node *> q;
    q.push(root);

    while (!q.empty())
    {
        Node *temp = q.front();
        q.pop();
        s.push(temp);

        if (temp->left)
            q.push(temp->left);

        if (temp->right)
            q.push(temp->right);
    }

    while (!s.empty())
    {
        cout << s.top()->data << " ";
        s.pop();
    }
    cout << endl;
}

/** for zig zag traversal, we need to store the current level stack, also the next level stack
 * depending on whether we are moving from left to right or otherwise, 
 * if left to right -> first push the left and then the right
 * else -> vice versa
 * at the end of each level we swap both the stacks cause the first one will be null
 * and second will be filled, we need current level as the second stack in nexxt level... if that
 * makes sense **/

void zigzagTraversal(Node *root)
{
    stack<Node *> currLevel, nextLevel;
    currLevel.push(root);

    bool lTof = true;
    while (!currLevel.empty())
    {
        Node *tmp = currLevel.top();
        currLevel.pop();
        if (tmp)
        {
            cout << tmp->data << " ";
            if (lTof)
            {
                if (tmp->left)
                    nextLevel.push(tmp->left);

                if (tmp->right)
                    nextLevel.push(tmp->right);
            }
            else
            {
                if (tmp->right)
                    nextLevel.push(tmp->right);
                if (tmp->left)
                    nextLevel.push(tmp->left);
            }

            if (currLevel.empty())
            {
                lTof = !lTof;
                swap(currLevel, nextLevel);
            }
        }
    }
}

/** Density of a binary tree is defined by size/height **/
float density(Node *root)
{
    if (root == NULL)
        return 0;

    int size = 0; // To store size

    // Finds height and size
    int _height = treeHeightandSize(root, size);

    return (float)size / _height;
}

int main()
{
    int n;
    cin >> n;
    int ar[n] = {0};
    for (int i = 0; i < n; i++)
        cin >> ar[i];

    Node *root = makeTree(ar, root, 0, n);
    printInOrder(root);
    cout << endl;
    // printLevelOrder(root), reverseLevelOrder(root);

    inorderIterative(root);
    //cout << "New node " << endl;
    // int k;
    // cin >> k;
    // insertNode(root, k);
    // cout << "\nDelete node " << endl;
    // int d;
    // cin >> d;
    // root = deletion(root, d);
    // printInOrder(root);
    int size = 0;
    int height = treeHeightandSize(root, size);
    cout << "\nHeight " << height << endl;
}
