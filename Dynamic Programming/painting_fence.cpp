#include <bits/stdc++.h>
using namespace std;

int fence(int n, int k)
{
    int dp[100010];
    memset(dp, 0, sizeof(dp));
    dp[1] = k, dp[2] = k * k;

    if (dp[n] != 0)
        return dp[n];

    if (n <= 0)
        return 0;

    if (n == 1)
        return k;

    if (n == 2)
        return k * k;

    dp[n] = (k - 1) * (fence(n - 1, k) + fence(n - 2, k));
    return dp[n];
}

int main()
{
    int n, k;
    cin >> n >> k;
    cout << fence(n, k);
}