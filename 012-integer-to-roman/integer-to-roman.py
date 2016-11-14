# -*- coding:utf-8 -*-


# Given an integer, convert it to a roman numeral.
#
#
# Input is guaranteed to be within the range from 1 to 3999.


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
