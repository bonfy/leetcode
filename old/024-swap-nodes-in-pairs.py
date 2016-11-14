# -*-coding:utf-8-*-

# Merge k sorted linked lists and return it as one sorted list.
# Analyze and describe its complexity.


# python version: Python 3

__Author = 'BONFY'


# Definition for singly-linked list.
class ListNode:
    def __init__(self, x):
        self.val = x
        self.next = None


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


class Solution2:
    def swapPairs(self, head):
        """
        :type head: ListNode
        :rtype: ListNode
        """
        pre, pre.next = self, head
        while pre.next and pre.next.next:
            pre.next, pre.next.next, pre.next.next.next = \
                      pre.next.next, pre.next, pre.next.next.next
            pre = pre.next.next
        return self.next


# 递归
class Solution3:
    def swapPairs(self, head):
        """
        :type head: ListNode
        :rtype: ListNode
        """
        if head and head.next:
            head, head.next, head.next.next = \
                  head.next, head, self.swapPairs(head.next.next)
        return head


if __name__ == '__main__':
    l1 = ListNode(1)
    l2 = ListNode(2)
    l3 = ListNode(3)
    l4 = ListNode(4)
    l5 = ListNode(5)

    l1.next = l2
    l2.next = l3
    l3.next = l4
    l4.next = l5

    result = Solution2().swapPairs(l1)
    while result:
        print(result.val, '->')
        result = result.next
