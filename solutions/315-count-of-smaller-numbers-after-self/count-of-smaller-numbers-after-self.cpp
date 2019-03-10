// You are given an integer array nums and you have to return a new counts array. The counts array has the property where counts[i] is the number of smaller elements to the right of nums[i].
//
// Example:
//
//
// Input: [5,2,6,1]
// Output: [2,1,1,0] 
// Explanation:
// To the right of 5 there are 2 smaller elements (2 and 1).
// To the right of 2 there is only 1 smaller element (1).
// To the right of 6 there is 1 smaller element (1).
// To the right of 1 there is 0 smaller element.
//
//


class Solution {
public:
    vector<int> countSmaller(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n), index(n);
        for (int i = 0; i < n; i++) {
            index[i] = i;
        }
        compute_inverse(nums, index, 0, n, ans);
        return ans;
    }
    void compute_inverse(vector<int>& nums, vector<int>& index, int l, int h, vector<int>& ans) {
        if (h - l <= 1) return;
        int m = l + (h - l) / 2;
        compute_inverse(nums, index, l, m, ans);
        compute_inverse(nums, index, m, h, ans);
        int p1 = l, p2 = m, rightcount = 0;
        vector<int> updated_index;
        while (p1 < m || p2 < h) {
            if (p2 == h || p1 < m && nums[index[p1]] <= nums[index[p2]]) {
                updated_index.emplace_back(index[p1]);
                ans[index[p1]] += rightcount;
                p1++;
            } else {
                updated_index.emplace_back(index[p2]);
                rightcount++;
                p2++;
            }
        }
        move(updated_index.begin(), updated_index.end(), index.begin() + l);
    }
};
