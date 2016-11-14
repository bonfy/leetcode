# -*-coding:utf-8-*-

# Given a binary tree, return the bottom-up level order traversal of its nodes' values. (ie, from left to right, level by level from leaf to root).

# For example:
# Given binary tree [3,9,20,null,null,15,7],
#     3
#    / \
#   9  20
#     /  \
#    15   7
# return its bottom-up level order traversal as:
# [
#   [15,7],
#   [9,20],
#   [3]
# ]

# python version: Python 3

__Author = 'BONFY'


# Definition for a binary tree node.
class TreeNode:
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None


class Solution:
    rlst = []

    def levelOrderBottom(self, root):
        """
        :type root: TreeNode
        :rtype: List[List[int]]
        """
        if not root:
            return []
        self.rlst = []
        self.levelList(root, 0)
        mx = max([item['hight'] for item in self.rlst])
        rst = [list() for _ in range(mx+1)]
        for item in self.rlst:
            rst[mx - item['hight']].append(item['val']) # for leetcode testcase order

        return rst

    def levelList(self, root, hight):
        if root:
            self.rlst.append({'val': root.val, 'hight': hight})
            hight = hight + 1
            if root.left:
                self.levelList(root.left, hight)
            if root.right:
                self.levelList(root.right, hight)


class Solution2:
    def levelOrderBottom(self, root):
        """
        :type root: TreeNode
        :rtype: List[List[int]]
        """
        answ, L = [], [root]
        while L and root:
            answ.insert(0, [n.val for n in L])
            L = [C for N in L for C in (N.left, N.right) if C]
        return answ


if __name__ == '__main__':
    root = TreeNode(3)

    l = TreeNode(9)
    r = TreeNode(20)

    l1 = TreeNode(15)
    r1 = TreeNode(7)

    root.left = l
    root.right = r

    r.left = l1
    r.right = r1

    print(Solution2().levelOrderBottom(root))
