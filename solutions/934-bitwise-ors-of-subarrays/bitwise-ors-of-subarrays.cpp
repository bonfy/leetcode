// We have an array A of non-negative integers.
//
// For every (contiguous) subarray B = [A[i], A[i+1], ..., A[j]] (with i <= j), we take the bitwise OR of all the elements in B, obtaining a result A[i] | A[i+1] | ... | A[j].
//
// Return the number of possible results.  (Results that occur more than once are only counted once in the final answer.)
//
//  
//
//
// Example 1:
//
//
// Input: [0]
// Output: 1
// Explanation: 
// There is only one possible result: 0.
//
//
//
// Example 2:
//
//
// Input: [1,1,2]
// Output: 3
// Explanation: 
// The possible subarrays are [1], [1], [2], [1, 1], [1, 2], [1, 1, 2].
// These yield the results 1, 1, 2, 1, 3, 3.
// There are 3 unique values, so the answer is 3.
//
//
//
// Example 3:
//
//
// Input: [1,2,4]
// Output: 6
// Explanation: 
// The possible results are 1, 2, 3, 4, 6, and 7.
//
//
//
//
//
//  
//
// Note:
//
//
// 	1 <= A.length <= 50000
// 	0 <= A[i] <= 10^9
//
//


class Solution {
public:
    int subarrayBitwiseORs(vector<int>& A) {
        vector<int> subor;
        for (int i = 0, s = 0, e = 0; i < A.size(); ++i, s = e, e = subor.size()) {
            subor.emplace_back(A[i]);
            for (int j = s; j < e; ++j) {
                if ((A[i] | subor[j]) != subor.back()) {
                    subor.emplace_back(subor[j] | A[i]);
                }
            }
        }
        return unordered_set<int>(subor.begin(), subor.end()).size();
    }
};
