#include <iostream>
using namespace std;
#include<vector>

int minPathSum(vector<vector<int>> &grid)
{
    int m=grid.size();
    int n=grid[0].size();

    int **dp=new int*[m];
    for(int i=0; i<m; i++){
        dp[i]=new int[n];
        for(int j=0; j<n; j++){
            dp[i][j]=0;
        }
    }

    dp[m-1][n-1]=grid[m-1][n-1];

    for(int i=m-2; i>=0; i--){
        dp[i][n-1]=dp[i+1][n-1]+grid[i][n-1];
    }

    for(int i=n-2; i>=0; i--){
        dp[m-1][i]=dp[m-1][i+1]+grid[m-1][i];
    }


    for(int i=m-2; i>=0; i--){
        for(int j=n-2; j>=0; j--){
            dp[i][j]=min(dp[i+1][j], dp[i][j+1])+ grid[i][j];
        }
    }

    return dp[0][0];
}

int main()
{

    vector<vector<int>> v={{1,3,1},{1,5,1},{4,2,1}};
    cout<<minPathSum(v)<<endl;
    return 0;
}