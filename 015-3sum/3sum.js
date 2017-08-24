// Given an array S of n integers, are there elements a, b, c in S such that a + b + c = 0? Find all unique triplets in the array which gives the sum of zero.
//
// Note: The solution set must not contain duplicate triplets.
//
//
// For example, given array S = [-1, 0, 1, 2, -1, -4],
//
// A solution set is:
// [
//   [-1, 0, 1],
//   [-1, -1, 2]
// ]


/**
 * @param {number[]} nums
 * @return {number[][]}
 */

var threeSum = function(nums) {
    nums = nums.sort((a,b) => a - b);
    let result = [];
    
    for (let i = 0; i < nums.length - 2; i++) {
        if (i > 0 && nums[i] === nums[i-1]) continue;   // skip the same result
        
        let j = i + 1;
        let k = nums.length - 1;
        let target = -nums[i];
        
        while (j < k) {
            if (nums[j] + nums[k] === target) {
                result.push([nums[i], nums[j], nums[k]]);
                
                j++; k--;
                while(j < k && nums[j] === nums[j - 1])   j++;    // skip the same result
                while(j < k && nums[k] === nums[k + 1])   k--;    // skip the same result
            } else if (nums[j] + nums[k] > target) {
                k--;
            } else {
                j++;
            }
        }
    }
    return result;
};
