// Given a collection of integers that might contain duplicates, nums, return all possible subsets (the power set).
//
// Note: The solution set must not contain duplicate subsets.
//
// Example:
//
//
// Input: [1,2,2]
// Output:
// [
//   [2],
//   [1],
//   [1,2,2],
//   [2,2],
//   [1,2],
//   []
// ]
//
//


class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        backtrack(nums, 0, {}, ans);
        return ans;
    }
    void backtrack(vector<int> nums, int idx, vector<int> path, vector<vector<int>>& ans) {
        ans.emplace_back(path);
        for (int i = idx; i < nums.size(); i++) {
            if (i == idx || nums[i] != nums[i - 1]) {
                path.emplace_back(nums[i]);
                backtrack(nums, i + 1, path, ans);
                path.pop_back();
            }
        }
    }
};
