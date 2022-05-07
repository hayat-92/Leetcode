#include <iostream>
using namespace std;
#include <vector>

int cherryPickup(vector<vector<int>> &grid)
{

    int m = grid.size();
    int n = grid[0].size();

    int **dp = new int *[m];
    for (int i = 0; i < m; i++)
    {
        dp[i] = new int[n];
        for (int j = 0; j < n; j++)
        {
            dp[i][j] = -1;
        }
    }

    // for (0, 0) to (n-1, n-1)

    dp[m - 1][n - 1] = grid[m - 1][n - 1];
    for (int i = m - 2; i >= 0; i--)
    {
        if (dp[i + 1][n - 1] != -1 && grid[i][n - 1] != -1)
        {
            dp[i][n - 1] = dp[i + 1][n - 1] + grid[i][n - 1];
            grid[i][n - 1] = 0;
        }
    }

    for (int i = n - 2; i >= 0; i--)
    {
        if (dp[m - 1][i + 1] != -1 && grid[m - 1][i] != -1)
        {
            dp[m - 1][i] = dp[m - 1][i + 1] + grid[m - 1][i];
            grid[m - 1][i] = 0;
        }
    }

    for (int i = m - 2; i >= 0; i--)
    {
        for (int j = n - 2; j >= 0; j--)
        {
            int val = max(dp[i + 1][j], dp[i][j + 1]);
            if (val != -1 && grid[i][j] != -1)
            {
                dp[i][j] = val + grid[i][j];
                grid[i][j] = 0;
            }
        }
    }

    int val = dp[0][0];
    cout<<val<<endl;

    for (int i = 0; i < m; i++)
    {
        delete[] dp[i];
    }

    delete[] dp;

    // for (n-1, n-1) to (0, 0)

    dp = new int *[m];
    for (int i = 0; i < m; i++)
    {
        dp[i] = new int[n];
        for (int j = 0; j < n; j++)
        {
            dp[i][j] = -1;
        }
    }

    if(val==-1){
        return 0;
    }

    dp[0][0] = val+grid[0][0];

    for (int i = 1; i < m; i++)
    {
        if (dp[i - 1][0] != -1 && grid[i][0] != -1)
        {
            dp[i][0] = dp[i - 1][0] + grid[i][0];
            grid[i][0] = 0;
        }
    }

    for (int i = 1; i < n; i++)
    {
        if (dp[0][i - 1] != -1 && grid[0][i] != -1)
        {
            dp[0][i] = dp[0][i - 1] + grid[0][i];
            grid[0][i] = 0;
        }
    }

    for (int i = 1; i < m; i++)
    {
        for (int j = 1; j < n; j++)
        {
            int val = max(dp[i - 1][j], dp[i][j - 1]);
            if (val != -1 && grid[i][j] != -1)
            {
                dp[i][j] = val + grid[i][j];
                grid[i][j] = 0;
            }
        }
    }

    int valFnl = dp[m - 1][n - 1];

    for (int i = 0; i < m; i++)
    {
        delete[] dp[i];
    }

    delete[] dp;
    if (valFnl == -1)
    {
        return 0;
    }
    else
    {
        return valFnl;
    }
}

int main()
{

    // vector<vector<int>> v={{1,1,-1},{1,-1,1},{-1,1,1}};
    // vector<vector<int>> v = {{0, 1, -1}, {1, 0, -1}, {1, 1, 1}};
    vector<vector<int>> v = {{1,1,1,1,0,0,0},{0,0,0,1,0,0,0},{0,0,0,1,0,0,1},{1,0,0,1,0,0,0},{0,0,0,1,0,0,0},{0,0,0,1,0,0,0},{0,0,0,1,1,1,1}};
    cout << cherryPickup(v);
    return 0;
}