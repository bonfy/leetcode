// Given a set of distinct positive integers, find the largest subset such that every pair (Si, Sj) of elements in this subset satisfies:
//
// Si % Sj = 0 or Sj % Si = 0.
//
// If there are multiple solutions, return any subset is fine.
//
// Example 1:
//
//
//
// Input: [1,2,3]
// Output: [1,2] (of course, [1,3] will also be ok)
//
//
//
// Example 2:
//
//
// Input: [1,2,4,8]
// Output: [1,2,4,8]
//
//
//


class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<int> T(nums.size(), 0);
        vector<int> parent(nums.size(), 0);
        int maxlen = 0, maxidx = 0;
        // 从右边开始往左扩充子集
        for (int i = nums.size() - 1; i >= 0; i--) {
            for (int j = i; j < nums.size(); j++) {
                if (nums[j] % nums[i] == 0 && T[i] < 1 + T[j]) {
                    T[i] = 1 + T[j];
                    parent[i] = j;
                    if (T[i] > maxlen) {
                        maxlen = T[i];
                        maxidx = i;
                    }
                }
            }
        }
        vector<int> ans;
        for (int i = 0; i < maxlen; i++) {
            ans.emplace_back(nums[maxidx]);
            maxidx = parent[maxidx];
        }
        return ans;
    }
};
