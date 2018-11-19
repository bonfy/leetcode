// Given a string S and a string T, find the minimum window in S which will contain all the characters in T in complexity O(n).
//
// Example:
//
//
// Input: S = "ADOBECODEBANC", T = "ABC"
// Output: "BANC"
//
//
// Note:
//
//
// 	If there is no such window in S that covers all characters in T, return the empty string "".
// 	If there is such window, you are guaranteed that there will always be only one unique minimum window in S.
//
//


class Solution {
public:
    string minWindow(string s, string t) {
        int minlen = INT_MAX, head = 0;
        vector<int> dict(256, 0);
        for (char c: t) {
            dict[c]++;
        }
        for (int slow = 0, fast = 0, cnt = 0; fast < s.size(); fast++) {
            if (dict[s[fast]]-- > 0) {
                cnt++;
            }
            while (cnt == t.size()) {
                int len = fast - slow + 1;
                if (len < minlen) {
                    head = slow;
                    minlen = len;
                }
                if (++dict[s[slow++]] > 0) {
                    cnt--;
                }
            }
        }
        return minlen == INT_MAX? "": s.substr(head, minlen);
    }
};
