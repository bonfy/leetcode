# -*- coding:utf-8 -*-


# Given a non-negative integer numRows, generate the first numRows of Pascal's triangle.
#
#
# In Pascal's triangle, each number is the sum of the two numbers directly above it.
#
# Example:
#
#
# Input: 5
# Output:
# [
#      [1],
#     [1,1],
#    [1,2,1],
#   [1,3,3,1],
#  [1,4,6,4,1]
# ]
#
#


class Solution(object):
    def generate(self, numRows):
        """
        :type numRows: int
        :rtype: List[List[int]]
        """
        if numRows == 0:
            return []
        
        if numRows == 1:
            return [[1]]
        
        tmp = self.generate(numRows-1)            
        # x = [0] + tmp[-1]
        # y = tmp[-1] + [0]
        # a = [x[i]+y[i] for i,_ in enumerate(x)]
        a = list(map(lambda x, y: x+y, tmp[-1] + [0], [0] + tmp[-1]))
        return tmp + [a]
