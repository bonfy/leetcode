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
        back(nums, 0, {}, ans);
        return ans;
    }
    void back(vector<int>& nums, int idx, vector<int> path, vector<vector<int>>& ans) {
        ans.emplace_back(path);
        for (int i = idx; i < nums.size(); i++) {
            path.emplace_back(nums[i]);
            back(nums, i + 1, path, ans);
            path.pop_back();
        }
    }
};
