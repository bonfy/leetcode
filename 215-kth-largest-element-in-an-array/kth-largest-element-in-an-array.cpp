// Find the kth largest element in an unsorted array. Note that it is the kth largest element in the sorted order, not the kth distinct element.
//
// Example 1:
//
//
// Input: [3,2,1,5,6,4] and k = 2
// Output: 5
//
//
// Example 2:
//
//
// Input: [3,2,3,1,2,4,5,5,6] and k = 4
// Output: 4
//
// Note: 
// You may assume k is always valid, 1 ≤ k ≤ array's length.
//


class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        return findk(nums, nums.size() - k, 0, nums.size() - 1);
    }
    int findk(vector<int>& nums, int k, int lo, int hi) {
        int l = lo, h = hi;
        while (l < h) {
            int p = partition(nums, l, h);
            if (p == k) return nums[p];
            if (p < k) {
                l = p + 1;
            } else {
                h = p - 1;
            }
        }
        return nums[l];
    }
    int partition(vector<int>& nums, int lo, int hi) {
        int l = lo, h = hi;
        int pivot = nums[l];
        while (l < h) {
            while (l < h && pivot < nums[h]) h--;
            if (l < h) nums[l++] = nums[h];
            while (l < h && nums[l] < pivot) l++;
            if (l < h) nums[h--] = nums[l];
        }
        nums[l] = pivot;
        return l;
    }
};
