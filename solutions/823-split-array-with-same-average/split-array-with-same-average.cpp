// In a given integer array A, we must move every element of A to either list B or list C. (B and C initially start empty.)
//
// Return true if and only if after such a move, it is possible that the average value of B is equal to the average value of C, and B and C are both non-empty.
//
//
// Example :
// Input: 
// [1,2,3,4,5,6,7,8]
// Output: true
// Explanation: We can split the array into [1,4,5,8] and [2,3,6,7], and both of them have the average of 4.5.
//
//
// Note:
//
//
// 	The length of A will be in the range [1, 30].
// 	A[i] will be in the range of [0, 10000].
//
//
//  
//


class Solution {
public:
    bool splitArraySameAverage(vector<int>& A) {
        int n = A.size(), k = n / 2, total = accumulate(A.begin(), A.end(), 0);
        bool sat = false;
        for (int i = 1; i <= k && !sat; i++) {
            if (total * i % n == 0) {
                sat = true;
            }
        }
        if (!sat) return false;
        // sum[x]: sums from x numbers of A
        vector<unordered_set<int>> sum(k + 1);
        sum[0].emplace(0);
        for (int e: A) {
            for (int i = k; i > 0; i--) {
                for (int presum: sum[i - 1]) {
                    sum[i].emplace(presum + e);
                }
            }
        }
        for (int i = 1; i <= k ; i++) {
            if (total * i % n == 0 && sum[i].count(total * i / n)) {
                return true;
            }
        }
        return false;
    }
};
