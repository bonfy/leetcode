# -*- coding:utf-8 -*-


# Given an index k, return the kth row of the Pascal's triangle.
#
#
# For example, given k = 3,
# Return [1,3,3,1].
#
#
#
# Note:
# Could you optimize your algorithm to use only O(k) extra space?


class Solution(object):
    def getRow(self, rowIndex):
        """
        :type rowIndex: int
        :rtype: List[int]
        """
        if rowIndex == 0:
            return [1]
        
        tmp = self.getRow(rowIndex-1)
        return list(map(lambda a,b:a+b, [0]+tmp, tmp+[0]))
