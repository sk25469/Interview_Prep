/** We find the order in which when traversed it gives an order such that 
 * all the nodes goes to the right when they are linearly arranged **/

#include <bits/stdc++.h>
using namespace std;

int dfs(int i, int node, vector<int> &ordering, vector<vector<int>> adj, vector<bool> &vis)
{
    vis[node] = true;
    vector<int> neighbour = adj[node];

    for (auto next : neighbour)
    {
        if (!vis[next])
            i = dfs(i, next, ordering, adj, vis);
    }

    ordering[i] = node; // we push the current node in the list of visited to maintain the order
    return i - 1;
}

vector<int> topologicalSort(vector<vector<int>> adj, int N)
{
    vector<bool> vis(N, false);
    vector<int> ordering(N, 0);
    int i = N - 1;                 // we start from last because visit the end nodes first
    for (int at = 0; at < N; at++) // we keep doing this until all the nodes are not visited
    {
        if (!vis[at])
            i = dfs(i, at, ordering, adj, vis);
    }

    return ordering;
}

int main()
{
    int n, e;
    cout << "Enter no. nodes and edges ";
    cin >> n >> e;

    vector<vector<int>> adj(n);
    for (int i = 0; i < e; i++)
    {
        int from, to;
        cin >> from >> to;
        adj[from].push_back(to);
    }

    vector<int> ordering = topologicalSort(adj, n);
    cout << "Topological ordering \n";
    for (auto x : ordering)
        cout << x << " ";
    cout << endl;
}