# -*- coding:utf-8 -*-


# Given a sorted array of integers, find the starting and ending position of a given target value.
#
# Your algorithm's runtime complexity must be in the order of O(log n).
#
# If the target is not found in the array, return [-1, -1].
#
#
# For example,
# Given [5, 7, 7, 8, 8, 10] and target value 8,
# return [3, 4].


class Solution(object):
    def searchRange(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: List[int]
        """
        n = len(nums)
        left, right = -1, -1
        l, r = 0, n-1
        while l < r:
            m = (l+r)/2
            if nums[m] < target: l = m+1
            else: r = m
        if nums[l] != target: return -1, -1
        left = l
        l, r = left, n-1
        while l < r:
            m = (l+r)/2+1
            if nums[m] == target: l = m
            else: r = m-1
        right = l
        return left, right
