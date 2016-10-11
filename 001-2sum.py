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


class Solution(object):
    def twoSum(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: List[int]
        """
        for i in range(len(nums)):
            if (target - nums[i]) in (nums[0:i] + [nums[i:]]):
                return sorted([i, nums.index(target - nums[i])])


if __name__ == '__main__':
    result = Solution().twoSum([3, 2, 4], 6)
    print(result)

    result = Solution().twoSum([0, 2, 1, 0], 0)
    print(result)
