// Given a non-negative integer num represented as a string, remove k digits from the number so that the new number is the smallest possible.
//
//
// Note:
//
// The length of num is less than 10002 and will be ≥ k.
// The given num does not contain any leading zero.
//
//
//
//
// Example 1:
//
// Input: num = "1432219", k = 3
// Output: "1219"
// Explanation: Remove the three digits 4, 3, and 2 to form the new number 1219 which is the smallest.
//
//
//
// Example 2:
//
// Input: num = "10200", k = 1
// Output: "200"
// Explanation: Remove the leading 1 and the number is 200. Note that the output must not contain leading zeroes.
//
//
//
// Example 3:
//
// Input: num = "10", k = 2
// Output: "0"
// Explanation: Remove all the digits from the number and it is left with nothing which is 0.
//
//


class Solution {
public:
    string removeKdigits(string num, int k) {
        if (k >= num.size()) return "0";
        vector<char> buf;
        int len = num.size() - k;
        buf.emplace_back(num[0]);
        for (int i = 1; i < num.size(); i++) {
            while (k > 0 && !buf.empty() && buf.back() > num[i]) {
                k--;
                buf.pop_back();
            }
            buf.emplace_back(num[i]);
        }
        buf.resize(len);
        int j = 0;
        while (j < buf.size() && buf[j] == '0') {
            j++;
        }
        string ans;
        for (; j < buf.size(); j++) {
            ans += buf[j];
        }
        return ans.empty()? "0": ans;
    }
};
