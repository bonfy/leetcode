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
        auto s(to_string(num));
        vector<int> maxpos(s.size(), s.size() - 1);
        for (int i = s.size() - 2, pos = s.size() - 1; i >= 0; i--) {
            if (s[i] > s[pos]) {
                pos = i;
            }
            maxpos[i] = pos;
        }
        for (int i = 0; i < s.size(); i++) {
            if (s[i] != s[maxpos[i]]) {
                swap(s[i], s[maxpos[i]]);
                break;
            }
        }
        return stoi(s);
    }
};
