#include <iostream>
#include <vector>
using namespace std;

int calculateMinimumHP(vector<vector<int>> &dungeon)
{
    int m = dungeon.size();
    int n = dungeon[0].size();
    int **dp = new int *[m];
    for (int i = 0; i < m; i++)
    {
        dp[i] = new int[n];
        for (int j = 0; j < n; j++)
        {
            dp[i][j] = 0;
        }
    }

    dp[m - 1][n - 1] = dungeon[m - 1][n - 1] >= 0 ? 1 : -dungeon[m - 1][n - 1]+1;

    for(int i=n-2; i>=0; i--){
        dp[m-1][i]=max(1, dp[m-1][i+1]-dungeon[m-1][i]);
    }

    for(int i=m-2; i>=0; i--){
        dp[i][n-1]=max(1, dp[i+1][n-1]-dungeon[i][n-1]);
    }

    for(int i=m-2; i>=0; i--){
        for(int j=n-2; j>=0; j--){
            int val=min(dp[i+1][j], dp[i][j+1]);
            dp[i][j]=max(1, val-dungeon[i][j]);
        }
    }

    int val= dp[0][0];

    for(int i=0; i<m; i++){
        delete [] dp[i];
    }

    delete [] dp;
    return val;
}

int main()
{
    vector<vector<int>> v={{-2,-3,3},{-5,-10,1},{10,30,-5}};
    cout<<calculateMinimumHP(v);
    return 0;
}