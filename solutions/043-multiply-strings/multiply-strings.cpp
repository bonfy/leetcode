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
        int m = num1.size(), n = num2.size();
        string ans(m + n, '0');
        for (int i = m - 1; i >= 0; i--) {
            for (int j = n - 1; j >= 0; j--) {
                int pos = i + j + 1, c_pos = i + j;
                int num = ans[pos] - '0' + (num1[i] - '0') * (num2[j] - '0');
                ans[c_pos] += num / 10;
                ans[pos] = num % 10 + '0';
            }
        }
        auto p = ans.find_first_not_of("0");
        if (p == string::npos) {
            return "0";
        }
        ans = ans.substr(p);
        return ans;
    }
};
