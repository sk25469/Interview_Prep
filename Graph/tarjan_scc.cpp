/** A strongly connected component of a graph is a subgraph 
 * such that all vertices of the subgraph are connected to each other, 
 * means we can reach every other vertices in the subgraph from any vertices **/

/** Tarjan's SCC algorithm uses stack to keep track of the nodes while we are visiting
 * such that all the nodes of which we have explored the neighbours, we will first push
 * them in the stack and when it is completed, we pop them one by one **/

/** We will also use the concept of low-link values, while giving the nodes initially
 * id == low_link, if the current has a low-link value equal to id, then it can be
 * the start of a SCC, but we can't be sure **/

#include <bits/stdc++.h>
#define pd pair<int, int>
using namespace std;

const int UNVISITED = -1;
int id = 0;     // to give the nodes unique id
int cntSCC = 0; // no. of SCCs

int n; // no. of nodes in the graph

vector<int> ids(n, 0);
vector<int> low_link(n, 0);
vector<bool> onStack(n, 0); // to keep track of which element is currently on stack

stack<int> st;

int main()
{
    int e;
    cout << "Enter no. nodes and edges ";
    cin >> n >> e;

    cout << "\nEnter the graph\n";

    vector<vector<pd>> adj(n);
    for (int i = 0; i < e; i++)
    {
        int from, to, weight;
        cin >> from >> to >> weight;
        adj[from].push_back({to, weight});
    }
}