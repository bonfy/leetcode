# -*- coding:utf-8 -*-


# Given a linked list and a value x, partition it such that all nodes less than x come before nodes greater than or equal to x.
#
#
# You should preserve the original relative order of the nodes in each of the two partitions.
#
#
# For example,
# Given 1-&gt;4-&gt;3-&gt;2-&gt;5-&gt;2 and x = 3,
# return 1-&gt;2-&gt;2-&gt;4-&gt;3-&gt;5.


# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution(object):
    def partition(self, head, x):
        """
        :type head: ListNode
        :type x: int
        :rtype: ListNode
        """
        h1 = t1 = ListNode(-1)
        h2 = t2 = ListNode(-1)
        dummy = head
        while dummy:
            if dummy.val < x:
                t1.next = dummy
                t1 = t1.next
            else:
                t2.next = dummy
                t2 = t2.next
            dummy = dummy.next
        t2.next = None
        t1.next = h2.next
        return h1.next
                
        
