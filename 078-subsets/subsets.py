# -*- coding:utf-8 -*-


# Given a set of distinct integers, nums, return all possible subsets (the power set).
#
# Note: The solution set must not contain duplicate subsets.
#
# Example:
#
#
# Input: nums = [1,2,3]
# Output:
# [
#   [3],
# &nbsp; [1],
# &nbsp; [2],
# &nbsp; [1,2,3],
# &nbsp; [1,3],
# &nbsp; [2,3],
# &nbsp; [1,2],
# &nbsp; []
# ]
#


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
