// Given an array of integers, return indices of the two numbers such that they add up to a specific target.
//
// You may assume that each input would have exactly one solution, and you may not use the same element twice.
//
// Example:
//
//
// Given nums = [2, 7, 11, 15], target = 9,
//
// Because nums[0] + nums[1] = 2 + 7 = 9,
// return [0, 1].
//
//


use std::collections::HashMap;

impl Solution {
    pub fn two_sum(nums: &mut Vec<i32>, target: i32) -> Vec<i32> {
        let mut seen = HashMap::new();
        for (i, num) in nums.iter().enumerate() {
            if seen.contains_key(num) {
                return vec![seen[num] as i32, i as i32];
            } else { seen.insert(target - num, i); }
        }
        vec![]
    }
}
