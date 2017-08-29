# -*- coding:utf-8 -*-


#
# Given a set of distinct integers, nums, return all possible subsets.
#
# Note: The solution set must not contain duplicate subsets.
#
#
# For example,
# If nums = [1,2,3], a solution is:
#
#
#
# [
#   [3],
#   [1],
#   [2],
#   [1,2,3],
#   [1,3],
#   [2,3],
#   [1,2],
#   []
# ]


class Solution(object):
    def subsets(self, nums):
        """
        :type nums: List[int]
        :rtype: List[List[int]]
        """
        if not nums:
            return [[]]
        else:
            last = nums[-1]
            tmp = self.subsets(nums[:-1])
            tmp2 = [i + [last] for i in tmp]
            return tmp+tmp2
