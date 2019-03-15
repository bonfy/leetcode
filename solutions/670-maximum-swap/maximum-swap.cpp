//
// Given a non-negative integer, you could swap two digits at most once to get the maximum valued number. Return the maximum valued number you could get.
//
//
// Example 1:
//
// Input: 2736
// Output: 7236
// Explanation: Swap the number 2 and the number 7.
//
//
//
// Example 2:
//
// Input: 9973
// Output: 9973
// Explanation: No swap.
//
//
//
//
// Note:
//
// The given number is in the range [0, 108]
//
//


class Solution {
public:
    int maximumSwap(int num) {
        string s(to_string(num));
        int n = s.size();
        int curMaxP = n - 1;
        vector<int> dppos(n, -1);
        for (int i = n - 1; i >= 0; i--) {
            if (s[i] > s[curMaxP]) {
                curMaxP = i;
            }
            dppos[i] = curMaxP;
        }
        for (int i = 0; i < n; i++) {
            if (s[i] != s[dppos[i]]) {
                swap(s[i], s[dppos[i]]);
                break;
            }
        }
        return stoi(s);
    }
};
