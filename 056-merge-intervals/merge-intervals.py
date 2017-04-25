# -*- coding:utf-8 -*-


# Given a collection of intervals, merge all overlapping intervals.
#
#
# For example,
# Given [1,3],[2,6],[8,10],[15,18],
# return [1,6],[8,10],[15,18].


# Definition for an interval.
# class Interval(object):
#     def __init__(self, s=0, e=0):
#         self.start = s
#         self.end = e

class Solution(object):
    def merge(self, intervals):
        """
        :type intervals: List[Interval]
        :rtype: List[Interval]
        """
        if not intervals:
            return []
        
        intervals.sort(key = lambda x: x.start, reverse=True)
        stack = []
        tmp = intervals.pop()
        while intervals:
            x = intervals.pop()
            if tmp.end >= x.start:
                tmp.end = max(tmp.end, x.end)
            else:
                stack.append(tmp)
                tmp = x
        stack.append(tmp)
        return stack
            
