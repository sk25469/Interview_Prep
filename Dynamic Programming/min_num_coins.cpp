/** Find min no. of coins to make a particular sum **/

#include <bits/stdc++.h>
using namespace std;

static int dp[1000][1000];

int minCoins(int coins[], int n, int target)
{

    // if we wont have any coin, then we need infinite amount of coins to make target sum
    for (int i = 0; i <= target; i++)
        dp[0][i] = INT_MAX - 1;

    // if we want 0 as sum, we wont need any coin from the bag
    for (int i = 1; i <= n; i++)
        dp[i][0] = 0;

    // we have to initialize the 2nd row here, since we only need the values from which
    // we can make target sum
    for (int i = 1; i <= target; i++)
    {
        if (i % coins[0] == 0)
            dp[1][i] = i / coins[0];
        else
            dp[1][i] = INT_MAX - 1;
    }
}