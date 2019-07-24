# -*- coding:utf-8 -*-


# Given a string s consists of upper/lower-case alphabets and empty space characters ' ', return the length of last word in the string.
#
# If the last word does not exist, return 0.
#
# Note: A word is defined as a character sequence consists of non-space characters only.
#
# Example:
#
#
# Input: "Hello World"
# Output: 5
#
#
#  
#


class Solution(object):
    def lengthOfLastWord(self, s):
        """
        :type s: str
        :rtype: int
        """
        if not s:
            return 0
            
        tmp = s.strip().split(' ')[-1]
        return len(tmp)
