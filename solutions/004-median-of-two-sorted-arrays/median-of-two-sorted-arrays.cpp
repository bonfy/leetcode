// There are two sorted arrays nums1 and nums2 of size m and n respectively.
//
// Find the median of the two sorted arrays. The overall run time complexity should be O(log (m+n)).
//
// You may assume nums1 and nums2 cannot be both empty.
//
// Example 1:
//
//
// nums1 = [1, 3]
// nums2 = [2]
//
// The median is 2.0
//
//
// Example 2:
//
//
// nums1 = [1, 2]
// nums2 = [3, 4]
//
// The median is (2 + 3)/2 = 2.5
//
//


class Solution {
public:
    double findKth(vector<int>& nums1, vector<int>& nums2, int k, int shift1, int shift2) {
        if (nums1.size() - shift1 > nums2.size() - shift2) {
            return findKth(nums2, nums1, k, shift2, shift1);
        }
        if (nums1.size() == shift1) {
            return nums2[k - 1 + shift2];
        }
        if (k == 1) {
            return min(nums1[shift1], nums2[shift2]);
        }
        int pa = min(static_cast<int>(nums1.size() - shift1), k/2);
        int pb = k - pa;
        if (nums1[pa - 1 + shift1] < nums2[pb -1 + shift2]) {
            return findKth(nums1, nums2, pb, shift1 + pa, shift2);
        } else if (nums1[pa - 1 + shift1] > nums2[pb -1 + shift2]) {
            return findKth(nums1, nums2, pa, shift1, shift2 + pb);
        } else {
            return nums1[pa - 1 + shift1];
        }
    }

    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int total_l = nums1.size() + nums2.size();
        if (total_l & 0x1) {
            return findKth(nums1, nums2, total_l / 2 + 1, 0, 0);
        } else {
            return (findKth(nums1, nums2, total_l / 2, 0, 0) + findKth(nums1, nums2, total_l / 2 + 1, 0, 0)) / 2.0;
        }
    }
};
