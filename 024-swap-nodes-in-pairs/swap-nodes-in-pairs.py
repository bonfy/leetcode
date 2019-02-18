# -*- coding:utf-8 -*-


# Given a linked list, swap every two adjacent nodes and return its head.
#
# You may not modify the values in the list's nodes, only nodes itself may be changed.
#
#  
#
# Example:
#
#
# Given 1->2->3->4, you should return the list as 2->1->4->3.
#
#


# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution(object):
    def swapPairs(self, head):
        """
        :type head: ListNode
        :rtype: ListNode
        """
        dummy = h = ListNode(0)
        step = 1
        tmp = None
        while head:
            if step % 2:
                tmp = ListNode(head.val)
            else:
                h.next = ListNode(head.val)
                h.next.next = tmp
                h = h.next.next
                tmp = None
            head = head.next
            step += 1
        if tmp:
            h.next = tmp
        return dummy.next
