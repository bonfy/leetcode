# -*- coding:utf-8 -*-


# Given a string containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.
#
# An input string is valid if:
#
#
# 	Open brackets must be closed by the same type of brackets.
# 	Open brackets must be closed in the correct order.
#
#
# Note that an empty string is also considered valid.
#
# Example 1:
#
#
# Input: "()"
# Output: true
#
#
# Example 2:
#
#
# Input: "()[]{}"
# Output: true
#
#
# Example 3:
#
#
# Input: "(]"
# Output: false
#
#
# Example 4:
#
#
# Input: "([)]"
# Output: false
#
#
# Example 5:
#
#
# Input: "{[]}"
# Output: true
#
#


class Solution(object):
    def isValid(self, s):
        """
        :type s: str
        :rtype: bool
        """
        pattern = {
            '(': ')',
            '{': '}',
            '[': ']'
            }
        lst = []
        end = None
        for item in s:
            if item in list(pattern.keys()):
                lst.append(item)
                end = item
            # elif end == None: # 起手是value 的情况
            #    return False
            elif end and pattern[end] == item:
                lst.pop()
                end = lst[-1] if lst else None
            else:
                return False
        return len(lst)==0
