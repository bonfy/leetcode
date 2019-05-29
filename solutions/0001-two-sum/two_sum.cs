using System;
using System.Collections.Generic;
using System.Text;

namespace leetcode._0001_Two_Sum
{
    /* 
     Given an array of integers, return indices of the two numbers such that they add up to a specific target.
     You may assume that each input would have exactly one solution, and you may not use the same element twice.

     Example:
     Given nums = [2, 7, 11, 15], target = 9,
     Because nums[0] + nums[1] = 2 + 7 = 9,
     return [0, 1].
     */
    public class two_sum
    {
        /// <summary>
        /// Time Complexity O（n^2）  Space Complexity（1）
        /// </summary>
        /// <param name="nums"></param>
        /// <param name="target"></param>
        /// <returns></returns>
        public static int[] TwoSum(int[] nums, int target)
        {
            for (int i = 0; i < nums.Length; i++)
            {
                for (int j = i + 1; j < nums.Length; j++)
                {
                    if (nums[i] + nums[j] == target)
                    {
                        return new int[] { i, j };
                    }
                }
            }
            return null;
        }
        /// <summary>
        /// Time Complexity O（n） Space Complexity O（n）
        /// </summary>
        /// <param name="nums"></param>
        /// <param name="target"></param>
        /// <returns></returns>
        public static int[] TwoSum1(int[] nums, int target)
        {
            Dictionary<int, int> keyValuePairs = new Dictionary<int, int>();
            for (int i = 0; i < nums.Length; i++)
            {
                int complement = target - nums[i];
                if (keyValuePairs.ContainsKey(complement))
                {
                    return new int[] { keyValuePairs[complement], i };
                }
                if (!keyValuePairs.ContainsKey(nums[i]))
                {
                    keyValuePairs.Add(nums[i], i);
                }
            }
            return null;
        }
    }
}
