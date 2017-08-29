# -*- coding:utf-8 -*-


# Given numRows, generate the first numRows of Pascal's triangle.
#
#
# For example, given numRows = 5,
# Return
#
# [
#      [1],
#     [1,1],
#    [1,2,1],
#   [1,3,3,1],
#  [1,4,6,4,1]
# ]
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
