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
# Given an integer, convert it to a roman numeral. Input is guaranteed to be within the range from 1 to 3999.
#
# Example 1:
#
#
# Input:&nbsp;3
# Output: &quot;III&quot;
#
# Example 2:
#
#
# Input:&nbsp;4
# Output: &quot;IV&quot;
#
# Example 3:
#
#
# Input:&nbsp;9
# Output: &quot;IX&quot;
#
# Example 4:
#
#
# Input:&nbsp;58
# Output: &quot;LVIII&quot;
# Explanation: C = 100, L = 50, XXX = 30 and III = 3.
#
#
# Example 5:
#
#
# Input:&nbsp;1994
# Output: &quot;MCMXCIV&quot;
# Explanation: M = 1000, CM = 900, XC = 90 and IV = 4.
#


class Solution(object):
    def intToRoman(self, num):
        """
        :type num: int
        :rtype: str
        """
        int2roman = {
            1: "I",
            4: "IV",
            5: "V",
            9: "IX",

            10: "X",
            40: "XL",
            50: "L",
            90: "XC",

            100: "C",
            400: "CD",
            500: "D",
            900: "CM",

            1000: "M"
        }

        builder = []
        components = [1, 4, 5, 9, 10, 10, 40, 50, 90, 100, 400, 500, 900, 1000]
        for item in reversed(components):
            while num >= item:
                builder.append(int2roman[item])
                num -= item
        return "".join(builder)
