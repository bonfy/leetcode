# -*- coding:utf-8 -*-


# Given a matrix of m x n elements (m rows, n columns), return all elements of the matrix in spiral order.
#
#
#
# For example,
# Given the following matrix:
#
#
# [
#  [ 1, 2, 3 ],
#  [ 4, 5, 6 ],
#  [ 7, 8, 9 ]
# ]
#
#
# You should return [1,2,3,6,9,8,7,4,5].


class Solution(object):
    def spiralOrder(self, matrix):
        """
        :type matrix: List[List[int]]
        :rtype: List[int]
        """
        if not matrix:
            return []
            
        result = []
        while len(matrix)>0:
            t = matrix.pop(0)
            matrix = self.trans(matrix)
            result += t
        return result
        

    def trans(self, matrix):
        return list(zip(*matrix))[::-1]
