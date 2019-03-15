// Given a collection of distinct integers, return all possible permutations.
//
// Example:
//
//
// Input: [1,2,3]
// Output:
// [
//   [1,2,3],
//   [1,3,2],
//   [2,1,3],
//   [2,3,1],
//   [3,1,2],
//   [3,2,1]
// ]
//
//


class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        pmt(nums, 0, ans);
        return ans;
    }
    void pmt(vector<int> nums, int idx, vector<vector<int>>& ans) {
        if (idx == nums.size()) {
            ans.emplace_back(nums);
        }
        for (int i = idx; i < nums.size(); i++) {
            swap(nums[i], nums[idx]);
            pmt(nums, idx+1, ans);
            swap(nums[i], nums[idx]);
        }
    }
};
