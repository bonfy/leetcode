# -*-coding:utf-8-*-

# There are two sorted arrays nums1 and nums2 of size m and n respectively.

# Find the median of the two sorted arrays. The overall run time complexity should be O(log (m+n)).

# Example 1:
# nums1 = [1, 3]
# nums2 = [2]

# The median is 2.0
# Example 2:
# nums1 = [1, 2]
# nums2 = [3, 4]

# The median is (2 + 3)/2 = 2.5
# Subscribe to see which companies asked this question

# python version: Python 3

__Author__ = 'BONFY'


class Solution(object):
    def findMedianSortedArrays(self, nums1, nums2):
        """
        :type nums1: List[int]
        :type nums2: List[int]
        :rtype: float
        """
        l = len(nums1) + len(nums2)
        return self.findKth(nums1, nums2, l//2) if l % 2 == 1 else (self.findKth(nums1, nums2, l//2-1)+self.findKth(nums1, nums2, l//2))/2.0

    def findKth(self, nums1, nums2, k):
        if len(nums1) > len(nums2):
            nums1, nums2 = nums2, nums1
        if not nums1:
            return nums2[k]
        if k == len(nums1) + len(nums2) - 1:
            return max(nums1[-1], nums2[-1])
        i = len(nums1)//2
        j = k-i
        if nums1[i] > nums2[j]:
            #Here I assume it is O(1) to get nums1[:i] and nums2[j:]. In python, it's not but in cpp it is.
            return self.findKth(nums1[:i], nums2[j:], i)
        else:
            return self.findKth(nums1[i:], nums2[:j], j)

if __name__ == '__main__':
    nums1 = [1, 3]
    nums2 = [2]
    print(Solution().findMedianSortedArrays(nums1, nums2))

    nums1 = [1, 2]
    nums2 = [3, 4]
    print(Solution().findMedianSortedArrays(nums1, nums2))

    nums1 = [2, 3, 4]
    nums2 = [1]
    print(Solution().findMedianSortedArrays(nums1, nums2))
