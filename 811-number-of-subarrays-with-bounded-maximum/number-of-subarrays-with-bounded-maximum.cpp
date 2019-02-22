// We are given an array A of positive integers, and two positive integers L and R (L <= R).
//
// Return the number of (contiguous, non-empty) subarrays such that the value of the maximum array element in that subarray is at least L and at most R.
//
//
// Example :
// Input: 
// A = [2, 1, 4, 3]
// L = 2
// R = 3
// Output: 3
// Explanation: There are three subarrays that meet the requirements: [2], [2, 1], [3].
//
//
// Note:
//
//
// 	L, R  and A[i] will be an integer in the range [0, 10^9].
// 	The length of A will be in the range of [1, 50000].
//
//


class Solution {
public:
    int numSubarrayBoundedMax(vector<int>& A, int L, int R) {
        int cnt = 0;
        int dp = 0;
        int prev = -1;
        for (int i = 0; i < A.size(); i++) {
            if (i and A[i] < L) {
                cnt += dp;
            }
            if (L <= A[i] and A[i] <= R) {
                dp = i - prev;
                cnt += dp;
            } 
            if (A[i] > R) {
                dp = 0;
                prev = i;
            }
        }
        return cnt;
    }
};
