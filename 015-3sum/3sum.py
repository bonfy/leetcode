# -*- coding:utf-8 -*-


# Given an array nums of n integers, are there elements a, b, c in nums such that a + b + c = 0? Find all unique triplets in the array which gives the sum of zero.
#
# Note:
#
# The solution set must not contain duplicate triplets.
#
# Example:
#
#
# Given array nums = [-1, 0, 1, 2, -1, -4],
#
# A solution set is:
# [
#   [-1, 0, 1],
#   [-1, -1, 2]
# ]
#
#


class Solution(object):
     def threeSum(self, nums):
        """
        :type nums: List[int]
        :rtype: List[List[int]]
        """
        nums.sort()
        res = []

        for i in range(len(nums)-1):  # because sums of 3 numbers
            if i == 0 or i > 0 and nums[i-1] != nums[i]:
            # avoid duplicate triplets [1 ,1, 1, -2]
                left = i + 1
                right = len(nums) - 1
                while left < right:   # two-way pointer
                    s = nums[i] + nums[left] + nums[right]
                    if s == 0:
                        res.append([nums[i], nums[left], nums[right]])
                        left += 1
                        right -= 1
                        while left < right and nums[left] == nums[left - 1]:
                            left += 1
                        while right > left and nums[right] == nums[right + 1]:
                            right -= 1
                    elif s < 0:
                        left += 1
                    else:
                        right -= 1
        return res
