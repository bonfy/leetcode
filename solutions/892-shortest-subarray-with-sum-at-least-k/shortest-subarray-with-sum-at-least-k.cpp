// Return the length of the shortest, non-empty, contiguous subarray of A with sum at least K.
//
// If there is no non-empty subarray with sum at least K, return -1.
//
//  
//
//
//
//
//
// Example 1:
//
//
// Input: A = [1], K = 1
// Output: 1
//
//
//
// Example 2:
//
//
// Input: A = [1,2], K = 4
// Output: -1
//
//
//
// Example 3:
//
//
// Input: A = [2,-1,2], K = 3
// Output: 3
//
//
//  
//
// Note:
//
//
// 	1 <= A.length <= 50000
// 	-10 ^ 5 <= A[i] <= 10 ^ 5
// 	1 <= K <= 10 ^ 9
//
//
//
//
//


class Solution {
public:
    int shortestSubarray(vector<int>& A, int K) {
        int n = A.size();
        vector<int> presum(n + 1, 0);
        for (int i = 0; i < n; i++) {
            presum[i + 1] = presum[i] + A[i];
        }
        deque<int> pos;
        int imin = INT_MAX;
        for (int i = 0; i <= n; i++) {
            while (pos.size() && presum[i] - presum[pos.front()] >= K) {
                imin = min(imin, i - pos.front());
                pos.pop_front();
            
            }
            while (pos.size() && presum[i] <= presum[pos.back()]) pos.pop_back();
            pos.emplace_back(i);
        }
        return imin == INT_MAX? -1: imin;
    }
};
