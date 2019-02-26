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
        string ans;
        int la = a.size() - 1, lb = b.size() - 1, c = 0;
        while (la >= 0 || lb >= 0 || c) {
            int sum = c;
            if (la >= 0) sum += a[la--] - '0';
            if (lb >= 0) sum += b[lb--] - '0';
            c = sum / 2;
            ans.insert(ans.begin(), 1, sum % 2 + '0');
        }
        return ans;
    }
};
