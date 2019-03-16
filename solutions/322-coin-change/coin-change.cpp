// You are given coins of different denominations and a total amount of money amount. Write a function to compute the fewest number of coins that you need to make up that amount. If that amount of money cannot be made up by any combination of the coins, return -1.
//
// Example 1:
//
//
// Input: coins = [1, 2, 5], amount = 11
// Output: 3 
// Explanation: 11 = 5 + 5 + 1
//
// Example 2:
//
//
// Input: coins = [2], amount = 3
// Output: -1
//
//
// Note:
// You may assume that you have an infinite number of each kind of coin.
//


class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount + 1, amount + 1);
        dp[0] = 0;
        for (int amt = 1; amt <= amount; amt++) {
            for (auto c: coins) {
                if (amt - c >= 0) {
                dp[amt] = min(dp[amt], dp[amt - c] + 1);
                }
            }
        }
        return dp.back() < amount + 1? dp.back(): -1;
    }
};
