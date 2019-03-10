//
// A message containing letters from A-Z is being encoded to numbers using the following mapping way:
//
//
//
// 'A' -> 1
// 'B' -> 2
// ...
// 'Z' -> 26
//
//
//
// Beyond that, now the encoded string can also contain the character '*', which can be treated as one of the numbers from 1 to 9.
//
//
//
//
// Given the encoded message containing digits and the character '*', return the total number of ways to decode it.
//
//
//
// Also, since the answer may be very large, you should return the output mod 109 + 7.
//
//
// Example 1:
//
// Input: "*"
// Output: 9
// Explanation: The encoded message can be decoded to the string: "A", "B", "C", "D", "E", "F", "G", "H", "I".
//
//
//
// Example 2:
//
// Input: "1*"
// Output: 9 + 9 = 18
//
//
//
// Note:
//
// The length of the input string will fit in range [1, 105].
// The input string will only contain the character '*' and digits '0' - '9'.
//
//


class Solution {
public:
    int numDecodings(string s) {
        if (s.empty()) return 0;
        long f1 = decode(s.substr(0, 1)), f2 = 1;
        for (int i = 1; i < s.size(); i++) {
            long f = f1 * decode(s.substr(i, 1)) + f2 * decode(s.substr(i - 1, 2));
            f2 = f1;
            f1 = f % 1000000007;
        }
        return f1;
    }
    int decode(string s) {
        if (s.size() == 1) {
            return s == "*"? 9: s == "0"? 0: 1;
        } else {
            if (s == "**") {
                return 15;
            } else if (s[0] == '*') {
                return s[1] <= '6'? 2: 1;
            } else if (s[1] == '*') {
                return s[0] == '1'? 9: s[0] == '2'? 6: 0;
            } else {
                int f = stoi(s);
                return 10 <= f and f <= 26;
            }
        }
    }
};
