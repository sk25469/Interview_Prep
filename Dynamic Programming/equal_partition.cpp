#include <bits/stdc++.h>
using namespace std;

/** Find if the array can be divided into 3 parts having the same sum**/
bool dp[1000][1000];

bool subsetSum(int ar[], int n, int sum)
{
    for (int i = 0; i <= sum; i++)
        dp[0][i] = false;

    for (int i = 0; i <= n; i++)
        dp[i][0] = true;

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= sum; j++)
        {
            if (ar[i - 1] <= j)
                dp[i][j] = dp[i - 1][j] || dp[i - 1][j - ar[i - 1]];
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
    int sum = 0;
    for (int i = 0; i < n; i++)
        cin >> ar[i], sum += ar[i];

    if (sum % 2)
        cout << "NO\n";
    else
    {
        if (subsetSum(ar, n, sum / 2))
            cout << "YES\n";
        else
            cout << "NO\n";
    }
}