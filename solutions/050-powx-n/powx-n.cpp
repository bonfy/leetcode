// Implement pow(x, n), which calculates x raised to the power n (xn).
//
// Example 1:
//
//
// Input: 2.00000, 10
// Output: 1024.00000
//
//
// Example 2:
//
//
// Input: 2.10000, 3
// Output: 9.26100
//
//
// Example 3:
//
//
// Input: 2.00000, -2
// Output: 0.25000
// Explanation: 2-2 = 1/22 = 1/4 = 0.25
//
//
// Note:
//
//
// 	-100.0 < x < 100.0
// 	n is a 32-bit signed integer, within the range [−231, 231 − 1]
//
//


class Solution {
public:
    double myPow(double x, int n) {
        bool neg = n < 0;
        double pre = 1.0;
        if (n == INT_MIN) {
            n += 1;
            pre = 1 / x;
        }
        double bin = 1.0;
        n = abs(n);
        while (n > 0) {
            if (n & 1) {
                bin *= x;
            }
            x *= x;
            n >>= 1;
        }
        double ans = neg? 1/bin: bin;
        return ans * pre;
    }
};
