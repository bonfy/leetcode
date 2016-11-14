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


# Solution TLE
class Solution:
    def mergeKLists(self, lists):
        """
        :type lists: List[ListNode]
        :rtype: ListNode
        """
        if not lists:
            return None
        from functools import reduce  # python3 need to import reduce
        result = reduce(self.mergeTwoLists, lists)
        return result

    def mergeTwoLists(self, l1, l2):
        """
        :type l1: ListNode
        :type l2: ListNode
        :rtype: ListNode
        """
        h = tail = ListNode(0)
        while l1 and l2:
            if l1.val <= l2.val:
                tail.next = l1
                l1 = l1.next
            else:
                tail.next = l2
                l2 = l2.next
            tail = tail.next

        tail.next = l1 or l2
        return h.next


class Solution2:
    def mergeKLists(self, lists):
        if not lists:
            return None
        import heapq
        dummyNode = cur = ListNode(0)
        minHeap = [(l.val, l) for l in lists if l]
        heapq.heapify(minHeap)
        while minHeap:
            cur.next = heapq.heappop(minHeap)[1]
            cur = cur.next
            if cur.next:
                heapq.heappush(minHeap, (cur.next.val, cur.next))
        return dummyNode.next


if __name__ == '__main__':
    l1 = ListNode(2)
    l2 = ListNode(4)
    l3 = ListNode(8)

    n1 = ListNode(3)
    n2 = ListNode(9)

    m1 = ListNode(0)
    m2 = ListNode(10)
    m3 = ListNode(15)

    l1.next = l2
    l2.next = l3
    n1.next = n2
    m1.next = m2
    m2.next = m3

    lists = [l1, n1, m1]

    result = Solution2().mergeKLists(lists)
    while result:
        print(result.val, '->')
        result = result.next
