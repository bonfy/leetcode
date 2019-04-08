# -*- coding:utf-8 -*-


# Given a linked list, reverse the nodes of a linked list k at a time and return its modified list.
#
# k is a positive integer and is less than or equal to the length of the linked list. If the number of nodes is not a multiple of k then left-out nodes in the end should remain as it is.
#
#
#
#
# Example:
#
# Given this linked list: 1->2->3->4->5
#
# For k = 2, you should return: 2->1->4->3->5
#
# For k = 3, you should return: 3->2->1->4->5
#
# Note:
#
#
# 	Only constant extra memory is allowed.
# 	You may not alter the values in the list's nodes, only nodes itself may be changed.
#
#


# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution(object):
    def reverseKGroup(self, head, k):
        """
        :type head: ListNode
        :type k: int
        :rtype: ListNode
        """
        if not head:
            return head

        h = head
        stack = []
        result = dummy = ListNode(-1)
        i = 0
        while h:
            
            stack.append(h.val)

            if len(stack) == k:
                tmp_head, tmp_tail = self.putStacktoLinkList(stack)
                stack = []
                dummy.next = tmp_head
                dummy = tmp_tail
            h = h.next

        if stack:
            for _,v in enumerate(stack):
                l = ListNode(v)
                dummy.next = l
                dummy = dummy.next
        return result.next

    def putStacktoLinkList(self, stack):
        head = cur = ListNode(stack.pop())
        while stack:
            l = ListNode(stack.pop())
            cur.next = l
            cur = cur.next
        return head, cur
            
