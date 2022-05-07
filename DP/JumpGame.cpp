#include <iostream>
#include<vector>
using namespace std;

int helper(vector<int> &nums, int index, int *dp){

    if(index>=nums.size()){
        return 0;
    }

    if(index==nums.size()-1){
        return 1;
    }

    if(dp[index]!=-1){
        return dp[index];
    }
    // if(nums[index]==0){
    //     return false;
    // }

    int val=nums[index];
    int flag=0;
    for(int i=1; i<=val; i++){
        int value= helper(nums, index+i, dp);
        if(value){
            flag=1;
            break;
        }else{
            continue;
        }
    
    }

    dp[index]=flag;

    return flag;

}

bool canJump(vector<int> &nums)
{

    int *dp=new int[nums.size()];
    for(int i=0; i<nums.size(); i++){
        dp[i]=-1;
    }

    int val= helper(nums, 0, dp);
    delete [] dp;
    if(val){
        return true;
    }else{
        return false;
    }
}

int main()
{
    vector<int> nums={2,3,1,1,4};

    
    cout<<canJump(nums)<<endl;
    return 0;
}