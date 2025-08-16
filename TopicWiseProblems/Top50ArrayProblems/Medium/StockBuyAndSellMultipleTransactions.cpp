/*
Stock Buy and Sell - Multiple Transaction Allowed
Last Updated : 23 Jul, 2025

Given an array prices[] of size n denoting the cost of stock on each day, the task is to find the maximum total profit if we can buy and sell the stocks any number of times.

Note: We can only sell a stock which we have bought earlier and we cannot hold multiple stocks on any day.

Problem link: https://www.geeksforgeeks.org/dsa/stock-buy-sell/

Examples:

    Input: prices[] = {100, 180, 260, 310, 40, 535, 695}
    Output: 865
    Explanation: Buy the stock on day 0 and sell it on day 3 => 310 - 100 = 210
                           Buy the stock on day 4 and sell it on day 6 => 695 - 40 = 655
                           Maximum Profit  = 210 + 655 = 865
*/

#include <iostream>
#include <vector>

using namespace std;

int maximumProfit(vector<int> &prices)
{
    int buy{prices[0]}, sell{prices[0]}, maxProfit{0};
    for (int i = 1; i < prices.size(); ++i)
    {
        if (prices[i] >= prices[i - 1])
        {
            sell = max(sell, prices[i]);
        }
        else
        {
            maxProfit += sell - buy;
            buy = prices[i];
            sell = buy;
        }
    }

    maxProfit += sell - buy;
    return maxProfit;
}