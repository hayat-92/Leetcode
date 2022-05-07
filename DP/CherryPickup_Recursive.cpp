#include<iostream> 
using namespace std;
#include<vector>
#include<climits>

int helper(int start_i, int start_j, int end_i,int end_j, vector<vector<int>> &grid, int **dp){
    if(start_i<0 || start_i>=end_i || start_j<0 || start_j>=end_j || grid[start_i][start_j]==-1){
        return -1;
    }

    if(dp[start_i][start_j]!=INT_MIN){
        return dp[start_i][start_j];
    }


    int val1=helper(start_i+1, start_j, end_i, end_j, grid, dp);
    int val2=helper(start_i, start_j+1, end_i, end_j, grid, dp);
    dp[start_i][start_j]=max(val1, val2)+grid[start_i][start_j];
}

int cherryPickup(vector<vector<int>> &grid){

}

int main(){
    return 0;
}