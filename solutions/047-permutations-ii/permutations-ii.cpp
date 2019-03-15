// Given a collection of numbers that might contain duplicates, return all possible unique permutations.
//
// Example:
//
//
// Input: [1,1,2]
// Output:
// [
//   [1,1,2],
//   [1,2,1],
//   [2,1,1]
// ]
//
//


class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> ans;
        sort(nums.begin(), nums.end());
        pmt(nums, 0, ans);
        return ans;
    }
    void pmt(vector<int> nums, int idx, vector<vector<int>>& ans) {
        if (idx == nums.size()) {
            ans.emplace_back(nums);
        }
        for (int i = idx; i < nums.size(); i++) {
            if (i > idx && nums[i] == nums[idx]) continue;
            swap(nums[i], nums[idx]);
            pmt(nums, idx + 1, ans);
            //swap(nums[i], nums[idx]);
        }
    }
};
