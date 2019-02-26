// Say you have an array for which the ith element is the price of a given stock on day i.
//
// Design an algorithm to find the maximum profit. You may complete as many transactions as you like (ie, buy one and sell one share of the stock multiple times) with the following restrictions:
//
//
// 	You may not engage in multiple transactions at the same time (ie, you must sell the stock before you buy again).
// 	After you sell your stock, you cannot buy stock on next day. (ie, cooldown 1 day)
//
//
// Example:
//
//
// Input: [1,2,3,0,2]
// Output: 3 
// Explanation: transactions = [buy, sell, cooldown, buy, sell]
//


class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int pre_p0 = 0, p0 = 0, p1 = INT_MIN;
        for (int p: prices) {
            int old_p0 = p0;
            p0 = max(p0, p1 + p);
            p1 = max(p1, pre_p0 - p);
            pre_p0 = old_p0;
        }
        return p0;
    }
};
