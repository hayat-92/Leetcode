#include <iostream>
#include <vector>
using namespace std;

void helper(vector<vector<int>> &grid, int start_i, int start_j, int end_i, int end_j, int m, int n, int &count, bool **dp)
{

    if (start_i < 0 || start_i >= m || start_j < 0 || start_j >= n || grid[start_i][start_j]==-1 || dp[start_i][start_j] == true)
    {
        return;
    }

    dp[start_i][start_j] = true;

    if (start_i == end_i && start_j == end_j)
    {

        bool flag=true;

        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (dp[i][j]==false && grid[i][j] !=-1)
                {
                    flag=false;
                }
            }
        }
        if(flag){
            count+=1;
        }
        dp[start_i][start_j]=false;
        return;
    }

    

    helper(grid, start_i + 1, start_j, end_i, end_j, m, n, count, dp);
    helper(grid, start_i, start_j + 1, end_i, end_j, m, n, count, dp);
    helper(grid, start_i - 1, start_j, end_i, end_j, m, n, count, dp);
    helper(grid, start_i, start_j - 1, end_i, end_j, m, n, count, dp);
    dp[start_i][start_j] = false;
}

int uniquePathsIII(vector<vector<int>> &grid)
{

    int m = grid.size();
    int n = grid[0].size();
    int start_i, start_j, end_i, end_j;
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (grid[i][j] == 1)
            {
                start_i = i;
                start_j = j;
            }

            if (grid[i][j] == 2)
            {
                end_i = i;
                end_j = j;
            }
        }
    }
    int count = 0;
    bool **dp = new bool *[m];
    for (int i = 0; i < m; i++)
    {
        dp[i] = new bool[n];
        for (int j = 0; j < n; j++)
        {
            dp[i][j] = false;
        }
    }
    helper(grid, start_i, start_j, end_i, end_j, m, n, count, dp);

    return count;
}

int main()
{
    vector<vector<int>> v={{1,0,0,0},{0,0,0,0},{0,0,0,2}};
    cout<<uniquePathsIII(v)<<endl;
    return 0;
}