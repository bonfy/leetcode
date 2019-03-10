// Given a positive integer n, return the number of all possible attendance records with length n, which will be regarded as rewardable. The answer may be very large, return it after mod 109 + 7.
//
// A student attendance record is a string that only contains the following three characters:
//
//
//
// 'A' : Absent. 
// 'L' : Late.
//  'P' : Present. 
//
//
//
//
// A record is regarded as rewardable if it doesn't contain more than one 'A' (absent) or more than two continuous 'L' (late).
//
// Example 1:
//
// Input: n = 2
// Output: 8 
// Explanation:
// There are 8 records with length 2 will be regarded as rewardable:
// "PP" , "AP", "PA", "LP", "PL", "AL", "LA", "LL"
// Only "AA" won't be regarded as rewardable owing to more than one absent times. 
//
//
//
// Note:
// The value of n won't exceed 100,000.
//
//
//
//


class Solution {
public:
    int checkRecord(int n) {
        if (n == 1) return 3;
        if (n == 2) return 8;
        int m = 1000000007;
        int A[n + 1] = {0};
        int P[n + 1] = {0};
        int L[n + 1] = {0};
        A[1] = 1;
        P[1] = 1;
        L[1] = 1;
        L[2] = 3;
        A[2] = 2;
        A[3] = 4;
        
        for (int i = 2; i <= n; i++) {
            P[i] = ((P[i - 1] + A[i - 1]) % m + L[i - 1]) % m;
            if (i >= 3) {
                L[i] = ((P[i - 1] + A[i - 1]) % m + (P[i - 2] + A[i - 2]) % m) % m;
            }
            if (i >= 4) {
                A[i] = ((A[i - 1] + A[i - 2]) % m + A[i - 3]) % m;
            }
        }
        return ((A[n] + P[n]) % m + L[n]) % m;
    }
};
