#include <bits/stdc++.h>
using namespace std;

static int dp[102][1000];

int fractionalKnapsackBrute(int wt[], int val[], int n, int W)
{

    if (n == 0 || W == 0)
        return 0;

    if (wt[n - 1] <= W)
        return max(val[n - 1] + fractionalKnapsackBrute(wt, val, n - 1, W - wt[n - 1]),
                   fractionalKnapsackBrute(wt, val, n - 1, W));

    else if (wt[n - 1] > W)
        return fractionalKnapsackBrute(wt, val, n - 1, W);
}

int fractionalKnapsack(int wt[], int val[], int n, int W)
{

    if (n == 0 || W == 0)
        return 0;

    if (dp[n][W] != -1)
        return dp[n][W];

    if (wt[n - 1] <= W)
    {
        dp[n][W] = max(val[n - 1] + fractionalKnapsack(wt, val, n - 1, W - wt[n - 1]),
                       fractionalKnapsack(wt, val, n - 1, W));
        return dp[n][W];
    }

    else if (wt[n - 1] > W)
    {
        dp[n][W] = fractionalKnapsack(wt, val, n - 1, W);
        return dp[n][W];
    }
}

int main()
{
    int n;
    cin >> n;
    cout << "Weight ";
    int wt[n] = {0};
    for (int i = 0; i < n; i++)
        cin >> wt[i];

    cout << "Value ";
    int val[n] = {0};
    for (int i = 0; i < n; i++)
        cin >> val[i];
    int W;
    cin >> W;
    memset(dp, -1, sizeof(dp));
    int mx = fractionalKnapsack(wt, val, n, W);
    cout << mx << endl;
}
