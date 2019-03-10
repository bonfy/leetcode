// Write a program to find the n-th ugly number.
//
// Ugly numbers are positive numbers whose prime factors only include 2, 3, 5. 
//
// Example:
//
//
// Input: n = 10
// Output: 12
// Explanation: 1, 2, 3, 4, 5, 6, 8, 9, 10, 12 is the sequence of the first 10 ugly numbers.
//
// Note:  
//
//
// 	1 is typically treated as an ugly number.
// 	n does not exceed 1690.
//


class Solution {
public:
    int nthUglyNumber(int n) {
        //vector<int> ugly(n, 1);
        int ugly[n] = {1};
        //ugly[0] = 1;
        int t2 = 0, t3 = 0, t5 = 0;
        for (int i = 1; i < n; i++) {
            ugly[i] = min(2 * ugly[t2], min(3 * ugly[t3], 5 * ugly[t5]));
            t2 += ugly[i] == 2 * ugly[t2];
            t3 += ugly[i] == 3 * ugly[t3];
            t5 += ugly[i] == 5 * ugly[t5];
        }
        return ugly[n - 1];
    }
};
