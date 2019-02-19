// Given a set of distinct integers, nums, return all possible subsets (the power set).
//
// Note: The solution set must not contain duplicate subsets.
//
// Example:
//
//
// Input: nums = [1,2,3]
// Output:
// [
//   [3],
//   [1],
//   [2],
//   [1,2,3],
//   [1,3],
//   [2,3],
//   [1,2],
//   []
// ]
//


class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        int n = nums.size();
        int nr = pow(2, n);
        vector<vector<int>> ans(nr);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < nr; j++) {
                if ((j >> i) & 1) {
                    ans[j].emplace_back(nums[i]);
                }
            }
        }
        return ans;
    }
};
