# -*- coding:utf-8 -*-


# The string "PAYPALISHIRING" is written in a zigzag pattern on a given number of rows like this: (you may want to display this pattern in a fixed font for better legibility)
#
# P   A   H   N
# A P L S I I G
# Y   I   R
#
#
# And then read line by line: "PAHNAPLSIIGYIR"
#
#
# Write the code that will take a string and make this conversion given a number of rows:
#
# string convert(string text, int nRows);
#
# convert("PAYPALISHIRING", 3) should return "PAHNAPLSIIGYIR".


class Solution(object):
    def convert(self, s, numRows):
        """
        :type s: str
        :type numRows: int
        :rtype: str
        """
        if not s or len(s) == 0 or numRows <= 0:
            return ""
        if numRows == 1:
            return s
        if len(s) % (numRows + numRows - 2):
            s = s + '#' * (numRows + numRows - 2 - (len(s) % (numRows + numRows - 2)))
        blocks = len(s)/(numRows + numRows - 2)
        res = ''
        for i in range(numRows):
            for j in range(blocks):
                if i == 0 or i == numRows-1:
                    res += s[i + j*(numRows + numRows - 2)]
                else:
                    res += s[i + j*(numRows + numRows - 2)]
                    res += s[2*numRows-2-i + j*(numRows + numRows - 2)]
        return ''.join(res.split('#'))

