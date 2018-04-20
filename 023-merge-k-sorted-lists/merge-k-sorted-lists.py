# -*- coding:utf-8 -*-


# Merge k sorted linked lists and return it as one sorted list. Analyze and describe its complexity.
#
# Example:
#
#
# Input:
# [
# &nbsp; 1-&gt;4-&gt;5,
# &nbsp; 1-&gt;3-&gt;4,
# &nbsp; 2-&gt;6
# ]
# Output: 1-&gt;1-&gt;2-&gt;3-&gt;4-&gt;4-&gt;5-&gt;6
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
