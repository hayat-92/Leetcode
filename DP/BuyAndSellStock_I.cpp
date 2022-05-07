#include <iostream>
#include <climits>
#include <vector>
using namespace std;

int maxProfit(vector<int> &prices)
{
    int minPrice = INT_MAX;
    int profit = 0;

    for (int i = 0; i < prices.size(); i++)
    {
        if (prices[i] < minPrice)
        {
            minPrice = prices[i];
        }
        else if (prices[i] - minPrice > profit)
        {
            profit = prices[i] - minPrice;
        }
    }

    return profit;
}

int main()
{
    vector<int> v = {7, 1, 5, 3};
    cout << maxProfit(v) << endl;
    return 0;
}