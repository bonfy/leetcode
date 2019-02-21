# -*- coding:utf-8 -*-


# Given a sorted linked list, delete all duplicates such that each element appear only once.
#
# Example 1:
#
#
# Input: 1->1->2
# Output: 1->2
#
#
# Example 2:
#
#
# Input: 1->1->2->3->3
# Output: 1->2->3
#
#


# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution(object):
    def deleteDuplicates(self, head):
        """
        :type head: ListNode
        :rtype: ListNode
        """
        t_point = head
        while t_point:
            while t_point.next and t_point.next.val == t_point.val:
                t_point.next = t_point.next.next
            t_point = t_point.next
        return head

