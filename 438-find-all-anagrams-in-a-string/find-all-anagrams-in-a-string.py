# -*- coding:utf-8 -*-


# Given a string s and a non-empty string p, find all the start indices of p's anagrams in s.
#
# Strings consists of lowercase English letters only and the length of both strings s and p will not be larger than 20,100.
#
# The order of output does not matter.
#
# Example 1:
#
# Input:
# s: "cbaebabacd" p: "abc"
#
# Output:
# [0, 6]
#
# Explanation:
# The substring with start index = 0 is "cba", which is an anagram of "abc".
# The substring with start index = 6 is "bac", which is an anagram of "abc".
#
#
#
# Example 2:
#
# Input:
# s: "abab" p: "ab"
#
# Output:
# [0, 1, 2]
#
# Explanation:
# The substring with start index = 0 is "ab", which is an anagram of "ab".
# The substring with start index = 1 is "ba", which is an anagram of "ab".
# The substring with start index = 2 is "ab", which is an anagram of "ab".
#
#


class Solution(object):
    def findAnagrams(self, s, p):
        """
        :type s: str
        :type p: str
        :rtype: List[int]
        """
        len_p = len(p)
        len_s = len(s)
        result = []
        
        if len_s < len_p:
            return result
        
        dct1 = self.stringtodict(s[:len_p])
        dct2 = self.stringtodict(p)
        if dct1 == dct2:
            result.append(0)
        
        for i in xrange(1,len_s-len_p+1):
            letter_remove = s[i-1]
            letter_add = s[len_p+i-1]
            dct1[letter_remove] -= 1
            if dct1[letter_remove] == 0:
                del dct1[letter_remove]
            if letter_add in dct1:
                dct1[letter_add] += 1
            else:
                dct1[letter_add] = 1
            if dct1 == dct2:
                result.append(i)
        return result
    
    def stringtodict(self, s):
        dct = {}
        
        for letter in s:
            if letter in dct:
                dct[letter] += 1
            else:
                dct[letter] = 1
        return dct
