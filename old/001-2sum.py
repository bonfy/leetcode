# -*-coding: utf-8-*-

# Given an array of integers, return indices of the two numbers
# such that they add up to a specific target.

# You may assume that each input would have exactly one solution.

# Example:
# Given nums = [2, 7, 11, 15], target = 9,

# Because nums[0] + nums[1] = 2 + 7 = 9,
# return [0, 1].

# python version: Python 3

__Author__ = 'BONFY'


class Solution:
    def twoSum(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: List[int]
        """
        for i in range(len(nums)):
            if (target - nums[i]) in (nums[0:i] + [nums[i:]]):
                return sorted([i, nums.index(target - nums[i])])


# GOOD CASE
class Solution2:
    def twoSum(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: List[int]
        """
        d = {}
        for i, v in enumerate(nums):
            if v in d:
                return [d[v], i]
            d[target-v] = i


if __name__ == '__main__':
    result = Solution2().twoSum([3, 2, 4], 6)
    print(result)

    result = Solution2().twoSum([0, 2, 1, 0], 0)
    print(result)
