# -*-coding:utf-8-*-

# Given n non-negative integers a1, a2, ..., an,
# where each represents a point at coordinate (i, ai).
# n vertical lines are drawn such that the two endpoints of line i is at (i, ai) and (i, 0).
# Find two lines, which together with x-axis forms a container,
# such that the container contains the most water.

# Note: You may not slant the container.

# python version: Python 3

__Auther__ = 'BONFY'


class Solution:
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
        components = list(sorted(int2roman.keys()))[::-1]
        for item in components:
            while num >= item:
                builder.append(int2roman[item])
                num -= item
        return "".join(builder)


if __name__ == '__main__':
    print(Solution().intToRoman(1))
    print(Solution().intToRoman(3999))
