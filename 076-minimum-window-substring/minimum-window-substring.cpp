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
        vector<int> letterofT(128, 0);
        for (char c: t) letterofT[c]++;
        int d = INT_MAX, head = 0;
        // counter: 多少个字符在t中
        for (int b = 0, e = 0, counter = 0; e < s.size(); e++) {
            // e遇到了t中字符
            if (letterofT[s[e]] > 0) {
                counter++;
            }
            // 使非t字符小于0， 或者标记已使用的t字符
            letterofT[s[e]]--;
            while (counter == t.size()) {
                int tmp = e - b + 1;
                if (tmp < d) {
                    d = tmp;
                    head = b;
                }
                letterofT[s[b]]++;
                // 将要跳过的是t字符
                if (letterofT[s[b]] > 0) {
                    counter--;
                }
                b++;
            }
        }
        return d == INT_MAX? "": s.substr(head, d);
    }
};
