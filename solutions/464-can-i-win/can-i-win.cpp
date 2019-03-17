// In the "100 game," two players take turns adding, to a running total, any integer from 1..10. The player who first causes the running total to reach or exceed 100 wins. 
//
// What if we change the game so that players cannot re-use integers? 
//
// For example, two players might take turns drawing from a common pool of numbers of 1..15 without replacement until they reach a total >= 100.
//
// Given an integer maxChoosableInteger and another integer desiredTotal, determine if the first player to move can force a win, assuming both players play optimally. 
//
// You can always assume that maxChoosableInteger will not be larger than 20 and desiredTotal will not be larger than 300.
//
//
// Example
//
// Input:
// maxChoosableInteger = 10
// desiredTotal = 11
//
// Output:
// false
//
// Explanation:
// No matter which integer the first player choose, the first player will lose.
// The first player can choose an integer from 1 up to 10.
// If the first player choose 1, the second player can only choose integers from 2 up to 10.
// The second player will win by choosing 10 and get a total = 11, which is >= desiredTotal.
// Same with other integers chosen by the first player, the second player will always win.
//
//


class Solution {
public:
    bool canIWin(int maxChoosableInteger, int desiredTotal) {
        if (desiredTotal <= maxChoosableInteger) return true;
        int sum = (1 + maxChoosableInteger) * maxChoosableInteger / 2;
        if (sum < desiredTotal) return false;
        vector<int> used(maxChoosableInteger + 1, 0);
        unordered_map<int, bool> mem;
        bool f= can(desiredTotal, maxChoosableInteger, used, mem);
        return f;
    }
    bool can(int total, int maxn, vector<int>& used, unordered_map<int, bool>& mem) {
        // 别人造成的total <= 0的情况， 自己进入这个情况已经输了
        if (total <= 0) return false;
        int key = format(used);
        if (!mem.count(key)) {
            for (int i = maxn; i >= 1; i--) {
                if (used[i]) continue;
                used[i] = 1;
                if (!can(total - i, maxn, used, mem)) {
                    // 推算到别人在这一步会输， 复原， 因为浅层思考可能用到这枚棋
                    used[i] = 0;
                    mem[key] = true;
                    return true;
                }
                used[i] = 0;
            }
            mem[key] = false;
        }
        return mem[key];
    }
    int format(vector<int>& used) {
        int ans = 0;
        for (int i = 0; i < used.size(); i++) {
            ans <<= 1;
            ans |= used[i];
        }
        return ans;
    }
};
