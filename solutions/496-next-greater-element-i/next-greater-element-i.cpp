//
// You are given two arrays (without duplicates) nums1 and nums2 where nums1’s elements are subset of nums2. Find all the next greater numbers for nums1's elements in the corresponding places of nums2. 
//
//
//
// The Next Greater Number of a number x in nums1 is the first greater number to its right in nums2. If it does not exist, output -1 for this number.
//
//
// Example 1:
//
// Input: nums1 = [4,1,2], nums2 = [1,3,4,2].
// Output: [-1,3,-1]
// Explanation:
//     For number 4 in the first array, you cannot find the next greater number for it in the second array, so output -1.
//     For number 1 in the first array, the next greater number for it in the second array is 3.
//     For number 2 in the first array, there is no next greater number for it in the second array, so output -1.
//
//
//
// Example 2:
//
// Input: nums1 = [2,4], nums2 = [1,2,3,4].
// Output: [3,-1]
// Explanation:
//     For number 2 in the first array, the next greater number for it in the second array is 3.
//     For number 4 in the first array, there is no next greater number for it in the second array, so output -1.
//
//
//
//
// Note:
//
// All elements in nums1 and nums2 are unique.
// The length of both nums1 and nums2 would not exceed 1000.
//
//


class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& findNums, vector<int>& nums) {
        unordered_map<int, int> loc;
        int s1 = findNums.size();
        int s2 = nums.size();
        if (!s1) {
            return findNums;
        }
        stack<int> s;
        s.emplace(nums[0]);
        for (int i = 1; i < s2; i++) {
            while (!s.empty() && nums[i] > s.top()) {
                loc.emplace(s.top(), nums[i]);
                s.pop();
            }
            s.emplace(nums[i]);
        }
        for (int i = 0; i < s1; i++) {
            findNums[i] = loc.count(findNums[i]) ? loc[findNums[i]]: -1;
        }
        
        return findNums;
    }
};
