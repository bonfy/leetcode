// Given two integers dividend and divisor, divide two integers without using multiplication, division and mod operator.
//
// Return the quotient after dividing dividend by divisor.
//
// The integer division should truncate toward zero.
//
// Example 1:
//
//
// Input: dividend = 10, divisor = 3
// Output: 3
//
// Example 2:
//
//
// Input: dividend = 7, divisor = -3
// Output: -2
//
// Note:
//
//
// 	Both dividend and divisor will be 32-bit signed integers.
// 	The divisor will never be 0.
// 	Assume we are dealing with an environment which could only store integers within the 32-bit signed integer range: [−231,  231 − 1]. For the purpose of this problem, assume that your function returns 231 − 1 when the division result overflows.
//
//


class Solution {
public:
    int divide(int dividend, int divisor) {
        if (divisor == 0 || (dividend == INT_MIN && divisor == -1)) return INT_MAX;
        bool posi = (dividend < 0) ^ (divisor < 0)? false: true;
        long dvd = labs(dividend);
        long dvs = labs(divisor);
        int ans = 0;
        while (dvd >= dvs) {
            int cnt = 1;
            long tmp = dvs;
            while (dvd >= (tmp << 1)) {
                tmp <<= 1;
                cnt <<= 1;
            }
            ans += cnt;
            dvd -= tmp;
        }
        return posi? ans: -ans;
    }
};
