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
        if (divisor == -1 and dividend == INT_MIN) return INT_MAX;
        if (divisor == 1) return dividend;
        if (divisor == -1) return -dividend;
        bool neg = (dividend < 0) ^ (divisor < 0);
        long dvd = labs(dividend), dvs = labs(divisor);
        int cnt = 0;
        while (dvd >= dvs) {
            int t = 1;
            long tmp = dvs;
            while (dvd >= tmp << 1) {
                t <<= 1;
                tmp <<= 1;
            }
            dvd -= tmp;
            cnt += t;
        }
        cnt = neg? -cnt: cnt;
        //cout << dividend - cnt * divisor << endl;
        return cnt;
    }
};
