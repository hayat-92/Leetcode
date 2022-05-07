#include <iostream>
#include <algorithm>
#include <cmath>
#include<vector>
#include <string>
using namespace std;

int helper(string s, int minJump, int maxJump, int index, int *dp)
{

    if (index == s.length() - 1)
    {
        return 1;
    }

    if (dp[index] ==1)
    {
        return 0;
    }

    int lRange = (index + minJump);
    int x = index + maxJump;
    int n = s.length();
    int rRange = min(x, n - 1);

    int result = 0;

    dp[index]=1;

    for (int j = lRange; j <= rRange; j++)
    {
        if (s[j] != '0')
        {
            continue;
        }

        int val = helper(s, minJump, maxJump, j, dp);
        if (val == 1)
        {
            return 1;
            // break;
        }
    }


    return 0;
}

bool canReach(string s, int minJump, int maxJump)
{
    // vector<int> *dp=new vector<int>(s.length(), -1);
    int *dp = new int[s.length()];
    for (int i = 0; i < s.length(); i++)
    {
        dp[i] = 0;
    }
    int val = helper(s, minJump, maxJump, 0, dp);

    // delete[] dp;
    delete dp;

    if (val == 1)
    {
        return true;
    }
    else
    {
        return false;
    }
}

int main()
{
    string s = "011010";
    int l = 2;
    int r = 3;
    cout << canReach(s, l, r) << endl;

    return 0;
}