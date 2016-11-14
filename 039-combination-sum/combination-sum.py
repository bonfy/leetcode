# -*- coding:utf-8 -*-


# Given a set of candidate numbers (C) and a target number (T), find all unique combinations in C where the candidate numbers sums to T. 
#
#
# The same repeated number may be chosen from C unlimited number of times.
#
#
# Note:
#
# All numbers (including target) will be positive integers.
# The solution set must not contain duplicate combinations.
#
#
#
#
# For example, given candidate set [2, 3, 6, 7] and target 7, 
# A solution set is: 
#
# [
#   [7],
#   [2, 2, 3]
# ]


class Solution(object):
    def combinationSum(self, candidates, target):
        """
        :type candidates: List[int]
        :type target: int
        :rtype: List[List[int]]
        """
        res = []
        candidates.sort()
        self.dfs(candidates, target, 0, [], res)
        return res
    
    def dfs(self, nums, target, index, path, res):
        if target < 0:
            return  # backtracking
        if target == 0:
            res.append(path)
            return 
        for i in xrange(index, len(nums)):
            self.dfs(nums, target-nums[i], i, path+[nums[i]], res)
