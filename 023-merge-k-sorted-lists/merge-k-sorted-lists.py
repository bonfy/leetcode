# -*- coding:utf-8 -*-


# Merge k sorted linked lists and return it as one sorted list. Analyze and describe its complexity.
#
# Example:
#
#
# Input:
# [
#   1->4->5,
#   1->3->4,
#   2->6
# ]
# Output: 1->1->2->3->4->4->5->6
#
#


# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution(object):
    def mergeKLists(self, lists):
        
        if not lists:
            return None

        dummyNode = cur = ListNode(0)
        minHeap = [(l.val, l) for l in lists if l]
        heapq.heapify(minHeap)

        while minHeap:
            cur.next = heapq.heappop(minHeap)[1]
            cur = cur.next

            if cur.next:
                heapq.heappush(minHeap, (cur.next.val, cur.next))

        return dummyNode.next
