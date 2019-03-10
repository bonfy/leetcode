// Your are given an array of integers prices, for which the i-th element is the price of a given stock on day i; and a non-negative integer fee representing a transaction fee.
// You may complete as many transactions as you like, but you need to pay the transaction fee for each transaction.  You may not buy more than 1 share of a stock at a time (ie. you must sell the stock share before you buy again.)
// Return the maximum profit you can make.
//
// Example 1:
//
// Input: prices = [1, 3, 2, 8, 4, 9], fee = 2
// Output: 8
// Explanation: The maximum profit can be achieved by:
// Buying at prices[0] = 1Selling at prices[3] = 8Buying at prices[4] = 4Selling at prices[5] = 9The total profit is ((8 - 1) - 2) + ((9 - 4) - 2) = 8.
//
//
//
// Note:
// 0 < prices.length <= 50000.
// 0 < prices[i] < 50000.
// 0 <= fee < 50000.
//


class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        int p_ik0 = 0, p_ik1 = INT_MIN;
        for (int p: prices) {
            int old_ik0 = p_ik0;
            p_ik0 = max(p_ik0, p_ik1 + p);
            p_ik1 = max(p_ik1, old_ik0 - p - fee);
        }
        return p_ik0;
    }
};
