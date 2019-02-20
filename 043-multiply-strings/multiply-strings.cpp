// Given two non-negative integers num1 and num2 represented as strings, return the product of num1 and num2, also represented as a string.
//
// Example 1:
//
//
// Input: num1 = "2", num2 = "3"
// Output: "6"
//
// Example 2:
//
//
// Input: num1 = "123", num2 = "456"
// Output: "56088"
//
//
// Note:
//
//
// 	The length of both num1 and num2 is < 110.
// 	Both num1 and num2 contain only digits 0-9.
// 	Both num1 and num2 do not contain any leading zero, except the number 0 itself.
// 	You must not use any built-in BigInteger library or convert the inputs to integer directly.
//
//


class Solution {
public:
    string multiply(string num1, string num2) {
        int n1 = num1.size(), n2 = num2.size();
        int n = n1 + n2;
        string ans(n, '0');
        for (int i = n1 - 1; i >= 0; --i) {
            for (int j = n2 - 1; j >= 0; --j) {
                int idx = i + j + 1, prev = i + j;
                int prod = ans[idx] - '0' + (num1[i] - '0') * (num2[j] - '0');
                ans[idx] = prod % 10 + '0';
                ans[prev] += prod / 10;
            }
        }
        auto p = ans.find_first_not_of('0');
        if (p == string::npos) {
            return "0";
        } else {
            ans = ans.substr(p);
        }
        return ans;
    }
};
