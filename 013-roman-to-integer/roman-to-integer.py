# -*- coding:utf-8 -*-


# Roman numerals are represented by seven different symbols:&nbsp;I, V, X, L, C, D and M.
#
#
# Symbol       Value
# I             1
# V             5
# X             10
# L             50
# C             100
# D             500
# M             1000
#
# For example,&nbsp;two is written as II&nbsp;in Roman numeral, just two one&#39;s added together. Twelve is written as, XII, which is simply X + II. The number twenty seven is written as XXVII, which is XX + V + II.
#
# Roman numerals are usually written largest to smallest from left to right. However, the numeral for four is not IIII. Instead, the number four is written as IV. Because the one is before the five we subtract it making four. The same principle applies to the number nine, which is written as IX. There are six instances where subtraction is used:
#
#
# 	I can be placed before V (5) and X (10) to make 4 and 9.&nbsp;
# 	X can be placed before L (50) and C (100) to make 40 and 90.&nbsp;
# 	C can be placed before D (500) and M (1000) to make 400 and 900.
#
#
# Given a roman numeral, convert it to an integer. Input is guaranteed to be within the range from 1 to 3999.
#
# Example 1:
#
#
# Input:&nbsp;&quot;III&quot;
# Output: 3
#
# Example 2:
#
#
# Input:&nbsp;&quot;IV&quot;
# Output: 4
#
# Example 3:
#
#
# Input:&nbsp;&quot;IX&quot;
# Output: 9
#
# Example 4:
#
#
# Input:&nbsp;&quot;LVIII&quot;
# Output: 58
# Explanation: C = 100, L = 50, XXX = 30 and III = 3.
#
#
# Example 5:
#
#
# Input:&nbsp;&quot;MCMXCIV&quot;
# Output: 1994
# Explanation: M = 1000, CM = 900, XC = 90 and IV = 4.
#


class Solution(object):
    def romanToInt(self, s):
        """
        :type s: str
        :rtype: int
        """
        roman = {"I":1, "V":5, "X":10, "L":50, "C":100, "D":500, "M":1000}
        total = 0
        for index in range(len(s)-1):
            type = 1 if roman[s[index]]>=roman[s[index+1]] else -1
            total += type*roman[s[index]]
        return total + roman[s[len(s)-1]]
