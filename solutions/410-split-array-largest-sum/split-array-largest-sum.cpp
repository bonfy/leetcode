// Given an array which consists of non-negative integers and an integer m, you can split the array into m non-empty continuous subarrays. Write an algorithm to minimize the largest sum among these m subarrays.
//
//
// Note:
// If n is the length of array, assume the following constraints are satisfied:
//
// 1 ≤ n ≤ 1000
// 1 ≤ m ≤ min(50, n)
//
//
//
// Examples: 
//
// Input:
// nums = [7,2,5,10,8]
// m = 2
//
// Output:
// 18
//
// Explanation:
// There are four ways to split nums into two subarrays.
// The best way is to split it into [7,2,5] and [10,8],
// where the largest sum among the two subarrays is only 18.
//
//


class Solution {
public:
    int splitArray(vector<int>& nums, int m) {
        int l = INT_MIN, h = 0;
        for (int n: nums) {
            h += n;
            l = max(l, n);
        }
        while (l < h) {
            int mid = l + (h - l) / 2;
            if (!cutable(nums, m - 1, mid)) {
                l = mid + 1;
            } else {
                h = mid;
            }
        }
        return l;
    }
    bool cutable(vector<int>& nums, int n, int lim) {
        int cur = 0;
        for (int i: nums) {
            if (i > lim) return false;
            if (cur + i <= lim) {
                cur = cur + i;
            } else {
                n -= 1;
                if (n < 0) return false;
                cur = i;
            }
        }
        return true;
    }
};
