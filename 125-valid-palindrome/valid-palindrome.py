# -*- coding:utf-8 -*-


# Given a string, determine if it is a palindrome, considering only alphanumeric characters and ignoring cases.
#
# Note:&nbsp;For the purpose of this problem, we define empty string as valid palindrome.
#
# Example 1:
#
#
# Input: &quot;A man, a plan, a canal: Panama&quot;
# Output: true
#
#
# Example 2:
#
#
# Input: &quot;race a car&quot;
# Output: false
#
#


class Solution(object):
    def isPalindrome(self, s):
        """
        :type s: str
        :rtype: bool
        """
        s = "".join([c.lower() for c in s if c.isalnum()])
        
        return s == s[::-1]
        
