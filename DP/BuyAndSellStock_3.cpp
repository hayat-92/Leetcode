#include <iostream>
#include <vector>
using namespace std;

int helper(vector<int> &prices, int n, int index, int buy, int k, vector<vector<vector<int>>> &dp)
{
    if (index >= n || k == 0)
    {
        return 0;
    }

    if (dp[index][buy][k] != -1)
    {
        return dp[index][buy][k];
    }

    if (buy==1)
    {
        int val1 = -prices[index] + helper(prices, n, index + 1, 0, k, dp);
        int val2 = helper(prices, n, index + 1, 1, k, dp);
        dp[index][buy][k] = max(val1, val2);
    }
    else
    {
        int val1 = prices[index] + helper(prices, n, index + 1, 1, k - 1, dp);
        int val2 = helper(prices, n, index + 1, 0, k, dp);
        dp[index][buy][k] = max(val1, val2);
    }

    return dp[index][buy][k];
}

int maxProfit(int x, vector<int> &prices)
{

    int n = prices.size();

    vector<vector<vector<int>>> dp(n + 1, vector<vector<int>>(2, vector<int>(x+1, -1)));

    return helper(prices, n, 0, 1, x, dp);
}

int main()
{

    cout<<(~12);

    return 0;
}