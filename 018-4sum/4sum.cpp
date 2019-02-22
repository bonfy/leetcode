// Given an array nums of n integers and an integer target, are there elements a, b, c, and d in nums such that a + b + c + d = target? Find all unique quadruplets in the array which gives the sum of target.
//
// Note:
//
// The solution set must not contain duplicate quadruplets.
//
// Example:
//
//
// Given array nums = [1, 0, -1, 0, -2, 2], and target = 0.
//
// A solution set is:
// [
//   [-1,  0, 0, 1],
//   [-2, -1, 1, 2],
//   [-2,  0, 0, 2]
// ]
//
//


class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> ans;
        sort(nums.begin(), nums.end());
        int n = nums.size();
        for (int i = 0; i <= n - 4; i++) {
            int n1 = nums[i];
            int target3 = target - n1;
            for (int j = i + 1; j <= n - 3; j++) {
                int n2 = nums[j];
                int target2 = target3 - n2;
                int l = j + 1, h = n - 1;
                while (l < h) {
                    int n3 = nums[l], n4 = nums[h];
                    int m = n3 + n4;
                    if (m == target2) {
                        ans.emplace_back(vector<int> {n1, n2, n3, n4});
                        while (l < h && nums[l] == n3) l++;
                        while (l < h && nums[h] == n4) h--;
                    } else if (m < target2) {
                        l++;
                    } else {
                        h--;
                    }
                }
                while (j + 1 <= n - 3 && nums[j + 1] == nums[j]) j++;
            }
            while (i + 1 <= n - 4 && nums[i + 1] == nums[i]) i++;
        }
        return ans;
    }
};
