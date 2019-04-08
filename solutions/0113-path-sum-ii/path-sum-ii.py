# -*- coding:utf-8 -*-


# Given a binary tree and a sum, find all root-to-leaf paths where each path's sum equals the given sum.
#
# Note: A leaf is a node with no children.
#
# Example:
#
# Given the below binary tree and sum = 22,
#
#
#       5
#      / \
#     4   8
#    /   / \
#   11  13  4
#  /  \    / \
# 7    2  5   1
#
#
# Return:
#
#
# [
#    [5,4,11,2],
#    [5,8,4,5]
# ]
#
#


# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution(object):
    def pathSum(self, root, sum):
        """
        :type root: TreeNode
        :type sum: int
        :rtype: List[List[int]]
        """
        if not root:
            return []
        
        if not root.left and not root.right and root.val == sum:
            return [[root.val]]
        
        r_left = []
        r_right = []
        
        if root.left:
            r_left = [[root.val] + l for l in self.pathSum(root.left, sum-root.val)]
            
        if root.right:
            r_right = [[root.val] + l for l in self.pathSum(root.right, sum-root.val)]
        
        return r_left + r_right
        
