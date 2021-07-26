/** In unbounded knapsack, we can take infinite amount of any product
 * This changes the way we will write the dp, if we can take a product, then
 * we will take it as much as we can before moving to the other ones **/

#include <bits/stdc++.h>
using namespace std;

static int dp[1000][1000];

int unboundedKnapsack(int wt[], int val[], int n, int W)
{
    for (int i = 0; i <= W; i++)
        dp[0][i] = 0;

    for (int i = 0; i <= n; i++)
        dp[i][0] = 0;

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= W; j++)
        {
            if (wt[i - 1] <= i)
                dp[i][j] = max(val[i - 1] + dp[i][j - wt[i - 1]], dp[i - 1][j]);
            else
                dp[i][j] = dp[i - 1][j];
        }
    }

    return dp[n][W];
}