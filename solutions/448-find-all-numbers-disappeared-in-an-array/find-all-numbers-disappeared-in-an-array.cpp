// Given an array of integers where 1 ≤ a[i] ≤ n (n = size of array), some elements appear twice and others appear once.
//
// Find all the elements of [1, n] inclusive that do not appear in this array.
//
// Could you do it without extra space and in O(n) runtime? You may assume the returned list does not count as extra space.
//
// Example:
//
// Input:
// [4,3,2,7,8,2,3,1]
//
// Output:
// [5,6]
//
//


class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        int size = nums.size();
        int aim_pos = 0;
        for (int i = 0; i < size; i++) {
            aim_pos = abs(nums[i]) - 1; // why abs? bug?
            if (nums[aim_pos] > 0) {
                nums[aim_pos] = -nums[aim_pos];
            }
        }
        vector<int> ans;
        for (int i = 0; i < size; i++) {
            if (nums[i] > 0) {
                ans.emplace_back(i + 1);
            }
        }
        return move(ans);
    }
};
