// A message containing letters from A-Z is being encoded to numbers using the following mapping:
//
//
// 'A' -> 1
// 'B' -> 2
// ...
// 'Z' -> 26
//
//
// Given a non-empty string containing only digits, determine the total number of ways to decode it.
//
// Example 1:
//
//
// Input: "12"
// Output: 2
// Explanation: It could be decoded as "AB" (1 2) or "L" (12).
//
//
// Example 2:
//
//
// Input: "226"
// Output: 3
// Explanation: It could be decoded as "BZ" (2 26), "VF" (22 6), or "BBF" (2 2 6).
//


class Solution {
public:
    int numDecodings(string s) {
        if (s.empty()) return 0;
        int f2 = 1, f1 = decode(s.substr(0, 1));
        for (int i = 1; i < s.size(); i++) {
            int cur = f1 * decode(s.substr(i, 1)) + f2 * decode(s.substr(i - 1, 2));
            f2 = f1;
            f1 = cur;
        }
        return f1;
    }
    int decode(string s) {
        if (s.size() == 1) {
            return s == "0"? 0: 1;
        } else {
            int n = stoi(s);
            return 10 <= n && n <= 26;
        }
    }
};
