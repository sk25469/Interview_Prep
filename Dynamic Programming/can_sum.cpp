/** Given an array of numbers and a target sum, check if the sum can be 
 * obtained by taking each numbers infinite amount of time
 * First we will develop a brute force algorithm by recursion and then improve
 * the time complexity by using dp **/

#include <bits/stdc++.h>
#include <time.h>
using namespace std;

bool bruteCanSum(vector<int> ar, int targetSum)
{

    if (targetSum == 0)
        return true;

    if (targetSum < 0)
        return false;

    for (int i = 0; i < ar.size(); i++)
    {
        int rem = targetSum - ar[i];
        if (bruteCanSum(ar, rem))
            return true;
    }

    return false;
}

/** The time complexity of the brute force is O(n^sum), because we are checking every 
 * integer the array each time the recursion stack is called, and max times the recursion
 * is called will be target sum
 * Space complexity will be O(m) since the recursion stack is going till m
 * m, the target sum **/

bool canSum(vector<int> ar, int targetSum, map<int, int> &mp)
{
    /** We will map if a particular sum can be obtained or not **/

    if (mp[targetSum] == 2 || mp[targetSum] == 3)
        return mp[targetSum];
    /** by default the map assigns values
    as 0 even to the keys which are not mapped, hence we have to use different values
    than 0 or 1 **/
    if (targetSum == 0)
        return true;
    if (targetSum < 0)
        return false;

    for (int i = 0; i < ar.size(); i++)
    {
        int rem = targetSum - ar[i];
        if (canSum(ar, rem, mp))
        {
            mp[targetSum] = 2;
            return true;
        }
    }

    mp[targetSum] = 3;
    return false;
}

/** This dp takes O(n*m) time as we are calling the stack n times and if we draw a recursion
 * tree for this, we will find the max depth of the tree to be m, and branching factor will
 * just be 1, m -> target sum
 * Space complexity will be just O(m), as we will use the map to store the keys
 * of the number of times stack is called **/

int main()
{
    int n;
    cout << "Enter n ";
    cin >> n;
    vector<int> ar(n);
    cout << "Enter elements\n";
    for (int i = 0; i < n; i++)
        cin >> ar[i];

    int sum;
    cout << "Enter sum ";
    cin >> sum;
    clock_t t;
    t = clock();
    map<int, int> x;
    cout << canSum(ar, sum, x) << endl;
    t = clock() - t;
    cout << "time : " << float(t) / CLOCKS_PER_SEC << " sec\n";
}