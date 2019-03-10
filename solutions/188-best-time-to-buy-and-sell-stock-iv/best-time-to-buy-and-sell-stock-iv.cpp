// Say you have an array for which the ith element is the price of a given stock on day i.
//
// Design an algorithm to find the maximum profit. You may complete at most k transactions.
//
// Note:
// You may not engage in multiple transactions at the same time (ie, you must sell the stock before you buy again).
//
// Example 1:
//
//
// Input: [2,4,1], k = 2
// Output: 2
// Explanation: Buy on day 1 (price = 2) and sell on day 2 (price = 4), profit = 4-2 = 2.
//
//
// Example 2:
//
//
// Input: [3,2,6,5,0,3], k = 2
// Output: 7
// Explanation: Buy on day 2 (price = 2) and sell on day 3 (price = 6), profit = 6-2 = 4.
//              Then buy on day 5 (price = 0) and sell on day 6 (price = 3), profit = 3-0 = 3.
//


class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
        if (k >= n / 2) {
            int p10 = 0, p11 = INT_MIN;
            for (int p: prices) {
                int old_p10 = p10;
                p10 = max(p10, p11 + p);
                p11 = max(p11, old_p10 - p);
            }
            return p10;
        } else {
            vector<int> p0(k + 1, 0), p1(k + 1, INT_MIN);
            for (int p: prices) {
                for (int t = k; t >= 1; t--) {
                    p0[t] = max(p0[t], p1[t] + p);
                    p1[t] = max(p1[t], p0[t - 1] - p);
                }
            }
            return p0[k];
        }
    }
};
