# -*- coding:utf-8 -*-


#
# Given n pairs of parentheses, write a function to generate all combinations of well-formed parentheses.
#
#
#
# For example, given n = 3, a solution set is:
#
#
# [
#   "((()))",
#   "(()())",
#   "(())()",
#   "()(())",
#   "()()()"
# ]
#


class Solution(object):
    def generateParenthesis(self, n):
        """
        :type n: int
        :rtype: List[str]
        """
        lst = []
        def generate(cur, left, right):
            
            if left > right:
                return
            if left == 0 and right == 0:
                lst.append(cur)
                return
            if left > 0:
                generate(cur + '(', left - 1, right)
            if right > 0:
                generate(cur + ')', left, right - 1)
        generate('', n, n)
        return lst
    

