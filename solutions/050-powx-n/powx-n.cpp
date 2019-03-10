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
        if (n == 0) return 1.0;
        bool z = n > 0;
        long absn = labs(n);
        double ans = 1.0;
        while (absn) {
            if (absn & 1) {
                ans *= x;
            }
            absn >>= 1;
            x *= x;
        }
        return z? ans: 1/ans;
    }
};
