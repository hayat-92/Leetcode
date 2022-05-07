#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;
ll uniquePathsWithObstacles(vector<vector<int>> &obstacleGrid)
{
    ll m = obstacleGrid.size();
    ll n = obstacleGrid[0].size();
    ll **dp = new ll *[m];
    for (ll i = 0; i < m; i++)
    {
        dp[i] = new ll[n];
        for (ll j = 0; j < n; j++)
        {
            dp[i][j] = 0;
        }
    }

    dp[m-1][n-1]=1^obstacleGrid[m-1][n-1];

    for (ll i = m-2; i >=0; i--)
    {
        if (obstacleGrid[i][n - 1] == 0)
        {
            dp[i][n - 1] = dp[i+1][n-1];
        }
        else
        {
            dp[i][n - 1] = 0;
        }
    }

    for (ll i = n-2; i >=0; i--)
    {
        if (obstacleGrid[m - 1][i] == 0)
        {
            dp[m - 1][i] = dp[m-1][i+1];
        }
        else
        {
            dp[m - 1][i] = 0;
        }
    }

    for (ll i = m - 2; i >= 0; i--)
    {
        for (ll j = n - 2; j >= 0; j--)
        {
            if (obstacleGrid[i][j] == 0)
            {
                dp[i][j] = dp[i + 1][j] + dp[i][j + 1];
            }
            else
            {
                dp[i][j] = 0;
            }
        }
    }

    ll value = dp[0][0];

    for (ll i = 0; i < m; i++)
    {
        if (obstacleGrid[i][n - 1] == 0)
        {
            dp[i][n - 1] = 1;
        }
        else
        {
            dp[i][n - 1] = 0;
        }
    }

    return value;
}

int main()
{

    vector<vector<int>> v={{0,0,0},{0,1,0},{0,0,0}};

    cout<<uniquePathsWithObstacles(v)<<endl;
    return 0;
}