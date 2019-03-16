// Given an array of integers and an integer k, you need to find the total number of continuous subarrays whose sum equals to k.
//
// Example 1:
//
// Input:nums = [1,1,1], k = 2
// Output: 2
//
//
//
// Note:
//
// The length of the array is in range [1, 20,000].
// The range of numbers in the array is [-1000, 1000] and the range of the integer k is [-1e7, 1e7].
//
//
//


class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int count = 0;
        int sum = 0;
        unordered_map<int, int> summap;
        summap[0] = 1;
        int size = nums.size();
        for (int i = 0; i < size; i++) {
            sum += nums[i];
            if (summap.find(sum - k) != summap.end()) {
                count += summap[sum - k];
            }
            if (summap.find(sum) != summap.end()) {
                summap[sum] += 1;
            } else {
                summap[sum] = 1;
            }
        }
        return count;
    }
};
