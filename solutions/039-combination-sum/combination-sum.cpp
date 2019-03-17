// Given a set of candidate numbers (candidates) (without duplicates) and a target number (target), find all unique combinations in candidates where the candidate numbers sums to target.
//
// The same repeated number may be chosen from candidates unlimited number of times.
//
// Note:
//
//
// 	All numbers (including target) will be positive integers.
// 	The solution set must not contain duplicate combinations.
//
//
// Example 1:
//
//
// Input: candidates = [2,3,6,7], target = 7,
// A solution set is:
// [
//   [7],
//   [2,2,3]
// ]
//
//
// Example 2:
//
//
// Input: candidates = [2,3,5], target = 8,
// A solution set is:
// [
//   [2,2,2,2],
//   [2,3,3],
//   [3,5]
// ]
//
//


class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        cmb(candidates, target, 0, {}, ans);
        return ans;
    }
    void cmb(vector<int>& candidates, int target, int idx, vector<int> path, vector<vector<int>>& ans) {
        if (target == 0) {
            ans.emplace_back(path);
            return;
        }
        for (int i = idx; i < candidates.size(); i++) {
            if (candidates[i] > target) continue;
            path.emplace_back(candidates[i]);
            cmb(candidates, target - candidates[i], i, path, ans);
            path.pop_back();
        }
    }
};
