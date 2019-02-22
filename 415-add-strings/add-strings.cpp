// Given two non-negative integers num1 and num2 represented as string, return the sum of num1 and num2.
//
// Note:
//
// The length of both num1 and num2 is < 5100.
// Both num1 and num2 contains only digits 0-9.
// Both num1 and num2 does not contain any leading zero.
// You must not use any built-in BigInteger library or convert the inputs to integer directly.
//
//


class Solution {
public:
    string addStrings(string num1, string num2) {
        int c = 0;
        string ans;
        int i = num1.size() - 1, j = num2.size() -1; 
        while (i >= 0 || j >= 0 || c) {
            int tmp = c;
            if (i >= 0) tmp += num1[i--] - '0';
            if (j >= 0) tmp += num2[j--] - '0';
            c = tmp / 10;
            ans.insert(ans.begin(), char(tmp % 10 + '0'));
        }
        return ans;
    }
    string subStrings(string num1, string num2) {
        if (num1.size() < num2.size() || (num1.size() == num2.size() && num1 < num2)) 
            return "-" + subStrings(num2, num1);
        int borrow = 0;
        string ans;
        int i = num1.size() - 1, j = num2.size() - 1;
        while (i >= 0 || j >= 0) {
            int tmp = -1 * borrow;
            int n = 0;
            if (i >= 0) tmp += num1[i--] - '0';
            if (j >= 0)  n = num2[j--] - '0';
            if (tmp < n) {
                tmp += 10;
                borrow = 1;
            } else {
                borrow = 0;
            }
            tmp -= n;
            ans.insert(ans.begin(), char(tmp % 10 + '0'));
        }
        auto p = ans.find_first_not_of('0');
        if (p != string::npos) {
            ans = ans.substr(p);
        } else {
            ans = "0";
        }
        return ans;
    }
    string generaladd(string s1, string s2) {
        if (s1[0] == '-' && s2[0] == '-') {
            return "-" + addStrings(s1.substr(1), s2.substr(1));
        }
        if (s1[0] != '-' && s2[0] != '-') {
            return addStrings(s1, s2);
        }
        if (s1[0] == '-' && s2[0] != '-') {
            return subStrings(s2, s1.substr(1));
        }
        if (s1[0] != '-' && s2[0] == '-') {
            return subStrings(s1, s2.substr(1));
        }
    }
};
