#include <bits/stdc++.h>
using namespace std;

/** Find the no. of subsets a sum can be represented from an array**/
int dp[1000][1000];

int numOfsubsetSum(int ar[], int n, int sum)
{
    for (int i = 0; i <= sum; i++)
        dp[0][i] = 0;

    for (int i = 0; i <= n; i++)
        dp[i][0] = 1;

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= sum; j++)
        {
            if (ar[i - 1] <= j)
                dp[i][j] = dp[i - 1][j] + dp[i - 1][j - ar[i - 1]];
            else
                dp[i][j] = dp[i - 1][j];
        }
    }

    return dp[n][sum];
}

int main()
{
    int n;
    cin >> n;
    memset(dp, 0, sizeof(dp));
    int ar[n];
    for (int i = 0; i < n; i++)
        cin >> ar[i];

    int sum;
    cin >> sum;
    cout << numOfsubsetSum(ar, n, sum);
}