# -*- coding:utf-8 -*-


# You are given two non-empty linked lists representing two non-negative integers. The digits are stored in reverse order and each of their nodes contain a single digit. Add the two numbers and return it as a linked list.
#
# You may assume the two numbers do not contain any leading zero, except the number 0 itself.
#
# Example:
#
#
# Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
# Output: 7 -> 0 -> 8
# Explanation: 342 + 465 = 807.
#
#


# Definition for singly-linked list.

# class ListNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution(object):
    def addTwoNumbers(self, l1, l2):
        """
        :type l1: ListNode
        :type l2: ListNode
        :rtype: ListNode
        """       
        if(l1 is None and l2 is None):
            return None

        head = ListNode(0)
        point = head
        carry = 0
        while l1 is not None and l2 is not None:
            s = carry + l1.val + l2.val
            point.next = ListNode(s % 10)
            carry = s / 10
            l1 = l1.next
            l2 = l2.next
            point = point.next
            
        while l1 is not None:
            s = carry + l1.val
            point.next = ListNode(s % 10)
            carry = s / 10
            l1 = l1.next
            point = point.next
        
        while l2 is not None:
            s = carry + l2.val
            point.next = ListNode(s % 10)
            carry = s / 10
            l2 = l2.next
            point = point.next
    
        if carry != 0:
            point.next = ListNode(carry)

        return head.next

        
        
        
