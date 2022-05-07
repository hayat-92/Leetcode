#include <iostream>
using namespace std;
#include <vector>
#include <climits>

int helper(vector<vector<int>> &grid, int r1, int c1, int r2, int c2, vector<vector<vector<vector<int>>>> &dp)
{
    // cout<<"Hao"<<endl;
    int n = grid.size();
    if (r1 >= n || c1 >= n || r2 >= n || c2 >= n || grid[r1][c1] == -1 || grid[r2][c2]==-1)
    {
        return INT_MIN;
    }

    if (r1 == n - 1 && c1 == n - 1)
    {
        return grid[r1][c1];
    }

    if(dp[r1][c1][r2][c2]!=0){
        return dp[r1][c1][r2][c2];
    }

    int cherries = 0;
    if (r1 == r2 && c1 == c2)
    {
        cherries += grid[r1][c1];
    }
    else
    {
        cherries = grid[r1][c1] + grid[r2][c2];
    }

    int val1 = helper(grid, r1 + 1, c1, r2 + 1, c2, dp);
    int val2 = helper(grid, r1, c1 + 1, r2, c2 + 1, dp);
    int val3 = helper(grid, r1 + 1, c1, r2, c2 + 1, dp);
    int val4 = helper(grid, r1, c1 + 1, r2 + 1, c2, dp);

    int fnl = max(max(val1, val2), max(val3, val4));
    cherries+=fnl;
    dp[r1][c1][r2][c2]=cherries;
    return cherries;
}

int cherryPickup(vector<vector<int>> &grid)
{

    int n=grid.size();

    vector<vector<vector<vector<int>>>> dp(n, vector<vector<vector<int>>>(n, vector<vector<int>>(n, vector<int>(n, 0))));

    // int ****dp=new int
    int val=helper(grid, 0, 0, 0, 0, dp);
    if(val==INT_MIN){
        return 0;
    }else{
        return val;
    }
}
int main()
{

    vector<vector<int>> v = {{1, 1, 1, 1, 0, 0, 0}, {0, 0, 0, 1, 0, 0, 0}, {0, 0, 0, 1, 0, 0, 1}, {1, 0, 0, 1, 0, 0, 0}, {0, 0, 0, 1, 0, 0, 0}, {0, 0, 0, 1, 0, 0, 0}, {0, 0, 0, 1, 1, 1, 1}};
    // cout << cherryPickup(v);
    cout<<('a'+1);
    return 0;
}