/** Calculate the minimum difference between all possible subsets in an array **/
/** We can solve it by thinking of this -
 * First we find the range of all values of all the subsets possible from 0 to sum
 * Now, let the first subset be s1, then other will be sum - s1
 * and we will assume s1 < sum-s1, so we will consider only the subsets whose sum
 * are less than sum/2
 * now diff = sum-s1 - s1 = diff(min)
 * diff(min) = sum-2*s1
 * this will be minimum when s1 is maximum **/

#include <bits/stdc++.h>
using namespace std;

/** Find the no. of subsets a sum can be represented from an array**/

bool dp[1000][1000];
vector<bool> subsetSum(int ar[], int n, int sum)
{
    vector<bool> res;
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

    for (int i = 0; i <= sum; i++)
        res.push_back(dp[n][i]);

    return res;
}

int main()
{
    int n;
    cin >> n;
    memset(dp, false, sizeof(dp));
    int ar[n], sum = 0;
    for (int i = 0; i < n; i++)
        cin >> ar[i], sum += ar[i];

    vector<bool> x = subsetSum(ar, n, sum);
    int mn = INT32_MAX;
    for (int i = 0; i <= sum / 2; i++)
    {
        if (x[i])
            mn = min(mn, sum - 2 * i);
    }

    cout << mn << endl;
}