# -*- coding:utf-8 -*-


#
# Follow up for &quot;Remove Duplicates&quot;:
# What if duplicates are allowed at most twice?
#
#
# For example,
# Given sorted array nums = [1,1,1,2,2,3],
#
#
# Your function should return length = 5, with the first five elements of nums being 1, 1, 2, 2 and 3. It doesn&#39;t matter what you leave beyond the new length.


class Solution(object):
    def removeDuplicates(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        # recode val counts to a dict
        i = 0
        for n in nums:
            if i < 2 or n > nums[i-2]:
                nums[i] = n
                i += 1
        return i
       
