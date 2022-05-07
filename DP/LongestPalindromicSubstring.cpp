#include <iostream>
#include <string>
#include <climits>
using namespace std;

string longestPalindrome(string s)
{
    string subStr = "";
    int length = 0;
    int n = s.length();
    for (int i = 0; i < n; i++)
    {
        // For odd length
        int l = i, r = i;
        while (l >= 0 && r < n && s[l] == s[r])
        {
            if (r - l + 1 > length)
            {
                length = r - l + 1;
                subStr = s.substr(l, r - l + 1);
            }
            l--;
            r++;
        }

        // For odd length
        l = i, r = i + 1;
        while (l >= 0 && r < n && s.at(l) == s.at(r))
        {
            if (r - l + 1 > length)
            {
                length = r - l + 1;
                subStr = s.substr(l, r - l + 1);
            }
            l--;
            r++;
        }
    }

    return subStr;
}

string longestPalindromeDP(string s)
{
    bool **dp = new bool *[s.length()];
    for (int i = 0; i < s.length(); i++)
    {
        dp[i] = new bool[s.length()];
    }

    string subStr = "";

    int n = s.length();
    for (int i = 0; i < n; i++)
    {
        for (int j = 0, k = i; k < n; j++, k++)
        {
            if (i == 0)
            {
                dp[j][k] = true;
            }
            else if (i == 1)
            {
                if (s[j] == s[k])
                {
                    dp[j][k] = true;
                }
                else
                {
                    dp[j][k] = false;
                }
            }
            else
            {
                if (s[j] == s[k])
                {
                    dp[j][k] = dp[j + 1][k - 1];
                }
                else
                {
                    dp[j][k] = false;
                }
            }
            if (dp[j][k])
            {
                subStr = s.substr(j, k - j + 1);
            }
        }
    }
    return subStr;
}

int main()
{

    string str;
    cin >> str;
    cout << longestPalindrome(str) << endl;
    cout << longestPalindromeDP(str) << endl;
    return 0;
}