# -*-coding:utf-8-*-

# You are given two linked lists representing two non-negative numbers.
# The digits are stored in reverse order and each of their nodes contain a single digit.
# Add the two numbers and return it as a linked list.

# Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
# Output: 7 -> 0 -> 8

# Definition for singly-linked list.

# python version: Python 3

__Author__ = 'BONFY'


class ListNode(object):
    def __init__(self, x):
        self.val = x
        self.next = None


class Solution(object):
    def addTwoNumbers(self, l1, l2):
        """
        :type l1: ListNode
        :type l2: ListNode
        :rtype: ListNode
        """
        # 特别注意
        # python3 / 与 // 的区别
        if(l1 is None and l2 is None):
            return None

        head = ListNode(0)
        point = head
        carry = 0
        while l1 is not None and l2 is not None:
            s = carry + l1.val + l2.val
            point.next = ListNode(s % 10)
            carry = s // 10
            l1 = l1.next
            l2 = l2.next
            point = point.next

        while l1 is not None:
            s = carry + l1.val
            point.next = ListNode(s % 10)
            carry = s // 10
            l1 = l1.next
            point = point.next

        while l2 is not None:
            s = carry + l2.val
            point.next = ListNode(s % 10)
            carry = s // 10
            l2 = l2.next
            point = point.next

        if carry != 0:
            point.next = ListNode(carry)

        return head.next


class Solution2(object):
    def addTwoNumbers(self, l1, l2):
        """
        :type l1: ListNode
        :type l2: ListNode
        :rtype: ListNode
        """
        dummy = ListNode(0)
        current, carry = dummy, 0

        while l1 or l2:
            val = carry
            if l1:
                val += l1.val
                l1 = l1.next
            if l2:
                val += l2.val
                l2 = l2.next
            carry, val = val // 10, val % 10
            current.next = ListNode(val)
            current = current.next

        if carry == 1:
            current.next = ListNode(1)

        return dummy.next

if __name__ == '__main__':
    a, a.next, a.next.next = ListNode(2), ListNode(4), ListNode(3)
    b, b.next, b.next.next = ListNode(5), ListNode(6), ListNode(4)
    result = Solution().addTwoNumbers(a, b)
    print("{0} -> {1} -> {2}".format(result.val, result.next.val, result.next.next.val))