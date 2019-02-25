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
        vector<vector<int>> ans;
        ans.emplace_back(vector<int>{});
        for (int i = 0; i < nums.size(); ++i) {
            for (int j = ans.size() - 1; j >= 0; --j) {
                ans.emplace_back(ans[j]);
                ans.back().emplace_back(nums[i]);
            }
        }
        return ans;
    }
};
