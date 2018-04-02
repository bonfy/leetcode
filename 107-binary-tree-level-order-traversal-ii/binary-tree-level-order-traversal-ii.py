# -*- coding:utf-8 -*-


# Given a binary tree, return the bottom-up level order traversal of its nodes' values. (ie, from left to right, level by level from leaf to root).
#
#
# For example:
# Given binary tree [3,9,20,null,null,15,7],
#
#     3
#    / \
#   9  20
#     /  \
#    15   7
#
#
#
# return its bottom-up level order traversal as:
#
# [
#   [15,7],
#   [9,20],
#   [3]
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
    rlst = []

    def levelOrderBottom(self, root):
        """
        :type root: TreeNode
        :rtype: List[List[int]]
        """
        if not root:
            return []
        self.rlst=[]
        self.levelList(root, 0)
        mx = max([item['hight'] for item in self.rlst])
        rst = [list() for _ in range(mx+1)]
        for item in self.rlst:
            rst[mx - item['hight']].append(item['val'])

        return rst

    def levelList(self, root, hight):
        if root:
            self.rlst.append({'val': root.val, 'hight': hight})
            hight = hight + 1
            if root.left:
                self.levelList(root.left, hight)
            if root.right:
                self.levelList(root.right, hight)

