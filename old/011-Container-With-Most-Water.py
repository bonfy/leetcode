# -*-coding:utf-8-*-

# Given n non-negative integers a1, a2, ..., an,
# where each represents a point at coordinate (i, ai).
# n vertical lines are drawn such that the two endpoints of line i is at (i, ai) and (i, 0).
# Find two lines, which together with x-axis forms a container,
# such that the container contains the most water.

# Note: You may not slant the container.

# python version: Python 3

__Auther__ = 'BONFY'


class Solution:
    def maxArea(self, height):
        """
        :type height: List[int]
        :rtype: int
        """
        max_area, i, j = 0, 0, len(height) - 1
        while i < j:
            max_area = max(max_area, min(height[i], height[j]) * (j - i))
            if height[i] < height[j]:
                i += 1
            else:
                j -= 1
        return max_area


#  Time Limit Exceeded
class Solution2:
    def maxArea(self, height):
        """
        :type height: List[int]
        :rtype: int
        """
        m, l = 0, len(height)
        for i in range(0, l//2):
            for j in range(i+1, l):
                m = max(m, min(height[i], height[j]) * (j-i))
        return m


if __name__ == '__main__':
    print(Solution().maxArea([28, 342, 418, 485, 719]))
