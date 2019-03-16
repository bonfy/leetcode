// Given a 32-bit signed integer, reverse digits of an integer.
//
// Example 1:
//
//
// Input: 123
// Output: 321
//
//
// Example 2:
//
//
// Input: -123
// Output: -321
//
//
// Example 3:
//
//
// Input: 120
// Output: 21
//
//
// Note:
// Assume we are dealing with an environment which could only store integers within the 32-bit signed integer range: [−231,  231 − 1]. For the purpose of this problem, assume that your function returns 0 when the reversed integer overflows.
//


class Solution {
public:
    int reverse(int x) {
        if (x == 0) {
            return x;
        }
        int sig = (x > 0) ? 1 : -1;
        int abs_x = abs(x);
        int res = abs_x;
        int i = 10;
        vector<int> num;
        while (res > 0) {
            num.emplace_back(res % i);
            res = res/i;
        }
        int digit = num.size();
        double ans = 0;
        double limit = pow(2,31);
        for (int j = 0; j < digit; ++j) {
            ans += num[j] * pow(10, digit - j - 1);
        }
        if (sig > 0) {
            if (ans > limit - 1) {
                return 0;
            }
        } else {
            if (ans > limit) {
                return 0;
            }
        }
        return sig * ans;
    }
};
