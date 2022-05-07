#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int helper(vector<int> &nums, int index, int *dp)
{

    if (index >= nums.size())
    {
        return INT_MAX;
    }
    if (index == nums.size() - 1)
    {
        return 0;
    }

    if(nums[index]==0){
        return INT_MAX;
    }

    if (dp[index] != -1)
    {
        return dp[index];
    }

    int value = INT_MAX;
    int element = nums[index];

    for (int i = 1; i <= element; i++)
    {
        int valx = helper(nums, index + i, dp);
        if (valx == INT_MAX)
        {
            continue;
        }
        else
        {

            value = min(value, 1 +valx);
        }
    }

    dp[index] = value;
    return value;
}

int jump(vector<int> &nums)
{
    int *dp = new int[nums.size()];
    for (int i = 0; i < nums.size(); i++)
    {
        dp[i] = -1;
    }

    int val = helper(nums, 0, dp);
    delete[] dp;
    return val;
}

int main()
{
    vector<int> nums = {2,3,1,1,4};
    cout << jump(nums);
    return 0;
}