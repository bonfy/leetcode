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
        const int n = nums.size();
        int l = 0, h = n - 1;
        function<int (int, int)> partition = [&](int l, int h){
            int idx = rand() % (h - l + 1) + l;
            swap(nums[l], nums[idx]);
            int pivot = nums[l];
            while (l < h) {
                while (l < h && pivot > nums[h]) --h;
                if (l < h) swap(nums[l++], nums[h]);
                while (l < h && nums[l] > pivot) ++l;
                if (l < h) swap(nums[l], nums[h--]);
            }
            nums[l] = pivot;
            return l;
        };
        while (l < h) {
            int m = partition(l, h);
            if (m == k - 1) return nums[m];
            if (m < k - 1) {
                l = m + 1;
            } else {
                h = m - 1;
            }
        }
        return nums[l];
    }
};
