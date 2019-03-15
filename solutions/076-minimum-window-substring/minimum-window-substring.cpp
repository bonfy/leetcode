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


class Solution {
public:
    string minWindow(string s, string t) {
        vector<int> freq(256, 0);
        for (char& c: t) {
            ++freq[c];
        }
        int head = -1, len = s.size() + 1;
        for (int slow = 0, fast = 0, cnt = 0; fast < s.size(); ++fast) {
            if (freq[s[fast]]-- > 0) {
                ++cnt;
            }
            while (cnt == t.size()) {
                int curlen = fast - slow + 1;
                if (curlen < len) {
                    len = curlen;
                    head = slow;
                }
                if (++freq[s[slow++]] > 0) {
                    --cnt;
                }
            }
        }
        return head == -1? "": s.substr(head, len);
    }
};
