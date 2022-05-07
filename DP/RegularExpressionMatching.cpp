#include <iostream>
using namespace std;

bool isMatch(string s, string p)
{
    int sL = s.length();
    int pL = p.length();
    bool **dp = new bool *[pL + 1];
    for (int j = 0; j < pL + 1; j++)
    {
        dp[j] = new bool[sL + 1];
    }

    for (int i = 0; i <= pL; i++)
    {
        for (int j = 0; j <= sL; j++)
        {
            if (i == 0 && j == 0)
            {
                dp[i][j] = true;
            }
            else if (i == 0)
            {
                dp[i][j] = false;
            }
            else if (j == 0)
            {
                if (s[i - 1] == '*')
                {
                    dp[i][j] = dp[i - 2][j];
                }
                else
                {
                    dp[i][j] = false;
                }
            }
            else
            {
                if (p[i - 1] == '*')
                {
                    dp[i][j] = dp[i - 2][j];
                    if (p[i - 2] == '.' || p[i - 2] == s[j - 1])
                    {
                        dp[i][j] = dp[i][j] || dp[i][j - 1];
                    }
                }
                else if (p[i - 1] == '.')
                {
                    dp[i][j] = dp[i-1][j-1];
                }else if(p[i-1]==s[j-1]){
                    dp[i][j]=dp[i-1][j-1];
                }else{
                    dp[i][j]=false;
                }
            }
        }
    }

    return dp[pL][sL];
}

int main()
{
    return 0;
}