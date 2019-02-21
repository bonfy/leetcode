# -*- coding:utf-8 -*-


# Given two integers n and k, return all possible combinations of k numbers out of 1 ... n.
#
# Example:
#
#
# Input: n = 4, k = 2
# Output:
# [
#   [2,4],
#   [3,4],
#   [2,3],
#   [1,2],
#   [1,3],
#   [1,4],
# ]
#
#


class Solution(object):
    def combine(self, n, k):
        """
        :type n: int
        :type k: int
        :rtype: List[List[int]]
        """
        if k == 1:
            return [[i] for i in range(1, n+1)]
        if n == k:
            return [[i for i in range(1, n+1)]]
        return [i + [n] for i in self.combine(n-1,k-1)] + [i for i in self.combine(n-1, k)]
