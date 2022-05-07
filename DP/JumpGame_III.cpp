#include <iostream>
#include <vector>
using namespace std;

bool helper(vector<int> &arr, int start, bool *dp)
{
    if (start < 0 || start >= arr.size())
    {
        return false;
    }

    if (arr[start] == 0)
    {
        return true;
    }
    if (dp[start])
    {
        return false;
    }

    dp[start] = true;

    bool val1 = helper(arr, start + arr[start], dp);
    if (val1)
    {
        return val1;
    }
    bool val2 = helper(arr, start - arr[start], dp);
    return val2;
}

bool canReach(vector<int> &arr, int start)
{
    bool *dp = new bool[arr.size()];
    for (int i = 0; i < arr.size(); i++)
    {
        dp[i] = false;
    }
    return helper(arr, start, dp);
}

int main()
{
    vector<int> v = {4, 2, 3, 0, 3, 1, 2};
    int start = 5;
    cout << canReach(v, start);
    return 0;
}