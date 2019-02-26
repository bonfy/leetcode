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
        int l = 0, h = nums.size() - 1;
        k -= 1;
        while (l < h) {
            int idx = partition(nums, l, h);
            if (idx == k) return nums[idx];
            if (idx < k) {
                l = idx + 1;
            } else {
                h = idx - 1;
            }
        }
        return nums[l];
    }
    int partition(vector<int>& nums, int l, int h) {
        int ix = random() % (h - l + 1) + l;
        swap(nums[l], nums[ix]);
        int pivot = nums[l];
        while (l < h) {
            while (l < h && pivot > nums[h]) h--;
            if (l < h) swap(nums[l++], nums[h]); 
            while (l < h && nums[l] > pivot) l++;
            if (l < h) swap(nums[l], nums[h--]); // 此处h-- 对边界更改 不可少
        }
        nums[l] = pivot;
        return l;
    }
};
