#include <iostream>
#include <vector>
using namespace std;

int maxVal=0;


void helperItr_2(vector<vector<int>> &grid, int start_i, int start_j, int value){
    if(start_i<0 || start_i>=grid.size() || start_j<0 || start_j>=grid.size() || grid[start_i][start_j]==-1){
        return;
    }

    if(start_i==0 && start_j==0){
        maxVal=max(value, maxVal);
        return;
    }

    int cherries=grid[start_i][start_j];
    grid[start_i][start_j]=0;
    // value+=cherries;
    helperItr_2(grid, start_i-1, start_j, value+cherries);
    helperItr_2(grid, start_i, start_j-1, value+cherries);
    // value-=cherries;
    grid[start_i][start_j]=cherries;


}

void helperItr_1(vector<vector<int>> &grid, int start_i, int start_j, int value){
    if(start_i<0 || start_i>=grid.size() || start_j<0 || start_j>=grid.size() || grid[start_i][start_j]==-1){
        return;
    }

    if(start_i == grid.size()-1 && start_j==grid.size()-1){
        helperItr_2(grid, start_i, start_j, value);
    }

    int cherries=grid[start_i][start_j];
    grid[start_i][start_j]=0;
    // value+=cherries;
    helperItr_1(grid, start_i+1, start_j, value+cherries);
    helperItr_1(grid, start_i, start_j+1, value+cherries);
    // value-=cherries;
    grid[start_i][start_j]=cherries;

}

int cherryPickup(vector<vector<int>> &grid)
{
    int value=0;
    helperItr_1(grid, 0, 0, value);
    return maxVal;
}
int main()
{
    vector<vector<int>> v = {{1,1,1,1,0,0,0},{0,0,0,1,0,0,0},{0,0,0,1,0,0,1},{1,0,0,1,0,0,0},{0,0,0,1,0,0,0},{0,0,0,1,0,0,0},{0,0,0,1,1,1,1}};
    cout << cherryPickup(v);
    return 0;
}