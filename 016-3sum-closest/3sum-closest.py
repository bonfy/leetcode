# -*- coding:utf-8 -*-


# Given an array S of n integers, find three integers in S such that the sum is closest to a given number, target. Return the sum of the three integers. You may assume that each input would have exactly one solution.
#
#
#     For example, given array S = {-1 2 1 -4}, and target = 1.
#
#     The sum that is closest to the target is 2. (-1 + 2 + 1 = 2).


class Solution(object):
    def threeSumClosest(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: int
        """
        nums.sort()
        result = sum(nums[:3])
        for i in range(len(nums) - 2):
            j, k = i+1, len(nums) - 1
            while j < k:
                s = nums[i] + nums[j] + nums[k]
                if s == target:
                    return s

                if abs(s - target) < abs(result - target):
                    result = s

                if s < target:
                    j += 1
                elif s > target:
                    k -= 1
        return result
