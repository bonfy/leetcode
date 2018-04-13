# -*- coding:utf-8 -*-


# Given two strings s and t, write a function to determine if t is an anagram of s.
#
# For example,
# s = &quot;anagram&quot;, t = &quot;nagaram&quot;, return true.
# s = &quot;rat&quot;, t = &quot;car&quot;, return false.
#
# Note:
# You may assume the string contains only lowercase alphabets.
#
# Follow up:
# What if the inputs contain unicode characters? How would you adapt your solution to such case?
#


class Solution(object):
    def isAnagram(self, s, t):
        """
        :type s: str
        :type t: str
        :rtype: bool
        """
        return self.stringtodict(s) == self.stringtodict(t)
    
    def stringtodict(self, s):
        dct = {}
        for letter in s:
            if letter in dct:
                dct[letter] += 1
            else:
                dct[letter] = 1
        return dct
            
