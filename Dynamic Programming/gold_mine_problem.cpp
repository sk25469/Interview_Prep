/** Given a gold mine of n*m dimensions. 
 * Each field in this mine contains a positive integer which is the amount of gold in tons. 
 * Initially the miner is at first column but can be at any row. 
 * He can move only (right->,right up /,right down\) that is from a given cell, 
 * the miner can move to the cell diagonally up towards the 
 * right or right or diagonally down towards the right. 
 * Find out maximum amount of gold he can collect. 
 * 
 * Examples - mat[][] = {{1, 3, 3},
                        {2, 1, 4},
                        {0, 6, 4}};
            Output : 12 
            {(1,0)->(2,1)->(2,2)}
**/

#include <bits/stdc++.h>
using namespace std;

int goldMineBrute(vector<vector<int>> ar, int x, int y)
{

    if (y == ar[0].size() - 1 && x >= 0 && x < ar.size())
        return ar[x][y];

    if (x >= ar.size() || y >= ar[0].size() || x < 0)
        return 0;

    return ar[x][y] + max(goldMineBrute(ar, x, y + 1),
                          max(goldMineBrute(ar, x - 1, y + 1), goldMineBrute(ar, x + 1, y + 1)));
}

/** Complexity for the brute force will be -- 
 * Since the branching factor is 3, and the maximum depth we can go is max(row,col) = n
 * O(3^n) 
 * Space complexity = O(n)  **/

int dp[100][100];
int goldMine(vector<vector<int>> ar, int x, int y)
{

    if (dp[x][y] != -1)
        return dp[x][y];

    if (y == ar[0].size() - 1 && x >= 0 && x < ar.size())
        return ar[x][y];

    if (x >= ar.size() || y >= ar[0].size() || x < 0)
        return 0;

    dp[x][y] = ar[x][y] + max(goldMineBrute(ar, x, y + 1),
                              max(goldMineBrute(ar, x - 1, y + 1), goldMineBrute(ar, x + 1, y + 1)));
    return dp[x][y];
}

/** after memoization, complexity becomes O(row*col) **/

int maxGold(vector<vector<int>> ar)
{

    int tot = 0;
    int res = INT32_MIN;
    for (int i = 0; i < ar.size(); i++)
    {
        tot = goldMineBrute(ar, i, 0);
        res = max(tot, res);
    }
    //cout << res << endl;

    return res;
}

int main()
{
    vector<vector<int>> ar = {{1, 3, 3},
                              {2, 1, 4},
                              {0, 6, 4}};

    memset(dp, -1, sizeof(dp));

    cout << maxGold(ar);
}