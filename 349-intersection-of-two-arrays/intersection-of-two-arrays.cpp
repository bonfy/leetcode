// Given two arrays, write a function to compute their intersection.
//
// Example 1:
//
//
// Input: nums1 = [1,2,2,1], nums2 = [2,2]
// Output: [2]
//
//
//
// Example 2:
//
//
// Input: nums1 = [4,9,5], nums2 = [9,4,9,8,4]
// Output: [9,4]
//
//
// Note:
//
//
// 	Each element in the result must be unique.
// 	The result can be in any order.
//
//
//  
//


class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        int n1 = nums1.size(), n2 = nums2.size();
        if (n1 < n2) return intersection(nums2, nums1);
        vector<int> ans;
        if (false) {
            unordered_set<int> uniq;
            for (auto& n: nums2) {
                uniq.emplace(n);
            }
            for (int& n: nums1) {
                if (uniq.count(n)) {
                    ans.emplace_back(n);
                    uniq.erase(n);
                }
            }
        } else {
            sort(nums1.begin(), nums1.end());
            sort(nums2.begin(), nums2.end());
            int j = 0;
            for (int i = 0; i < n2; ++i) {
                if (i && nums2[i] == nums2[i - 1]) continue;
                auto pos = lower_bound(nums1.begin() + j, nums1.end(), nums2[i]);
                if (pos == nums1.end()) break;
                if (*pos == nums2[i]) {
                    ans.emplace_back(nums2[i]);
                    j = pos - nums1.begin() + 1;
                } else
                j = pos - nums1.begin();
            }
        }
        
            return ans;
    }
};
