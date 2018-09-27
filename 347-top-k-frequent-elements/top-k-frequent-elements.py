# -*- coding:utf-8 -*-


# Given a non-empty array of integers, return the k most frequent elements.
#
# Example 1:
#
#
# Input: nums = [1,1,1,2,2,3], k = 2
# Output: [1,2]
#
#
#
# Example 2:
#
#
# Input: nums = [1], k = 1
# Output: [1]
#
#
# Note: 
#
#
# 	You may assume k is always valid, 1 ≤ k ≤ number of unique elements.
# 	Your algorithm's time complexity must be better than O(n log n), where n is the array's size.
#
#


class Solution(object):
    def topKFrequent(self, nums, k):
        """
        :type nums: List[int]
        :type k: int
        :rtype: List[int]
        """
        d = dict()
        for item in nums:
            if item in d:
                d[item] += 1
            else:
                d[item] = 1
        arr1 = sorted(d.iteritems(), key=lambda asd:asd[1], reverse=True)
        arr2 = []
        for key in range(len(arr1)):
            arr2.append(arr1[key][0])
        return arr2[0:k]
