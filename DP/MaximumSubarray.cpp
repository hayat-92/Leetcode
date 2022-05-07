#include <iostream>
#include <vector>
using namespace std;

int maxSubArray(vector<int> &nums)
{
    int maxSum = nums.at(0);
    int currSum = 0;
    for (int i = 1; i < nums.size(); i++)
    {
        currSum += nums.at(i);
        if (currSum > maxSum)
        {
            maxSum = currSum;
        }
        if (currSum < 0)
        {
            currSum = 0;
        }

        
    }

    return maxSum;
}

int main()
{

    return 0;
}