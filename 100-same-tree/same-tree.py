# -*- coding:utf-8 -*-


# Given two binary trees, write a function to check if they are equal or not.
#
#
# Two binary trees are considered equal if they are structurally identical and the nodes have the same value.


# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution(object):
    def isSameTree(self, p, q):
        """
        :type p: TreeNode
        :type q: TreeNode
        :rtype: bool
        """
        if p is None and q is None:
            return True
        if p is None and q:
            return False
        if q is None and p:
            return False
        return p.val == q.val and self.isSameTree(p.left, q.left) and self.isSameTree(p.right, q.right)
