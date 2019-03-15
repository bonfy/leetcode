// Given two binary strings, return their sum (also a binary string).
//
// The input strings are both non-empty and contains only characters 1 or 0.
//
// Example 1:
//
//
// Input: a = "11", b = "1"
// Output: "100"
//
// Example 2:
//
//
// Input: a = "1010", b = "1011"
// Output: "10101"
//


class Solution {
public:
    string addBinary(string a, string b) {
        int m = a.size(), n = b.size();
        int i = m - 1, j = n - 1, c = 0;
        string ans;
        while (i >= 0 || j >= 0 || c) {
            int val = c;
            if (i >= 0) {
                val += a[i--] - '0';
            }
            if (j >= 0) {
                val += b[j--] - '0';
            }
            c = val / 2;
            ans.insert(ans.begin(), 1, val % 2 + '0');
        }
        return ans;
    }
};
