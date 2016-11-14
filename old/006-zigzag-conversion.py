# -*-coding:utf-8-*-

# The string "PAYPALISHIRING" is written in a zigzag pattern on a given number of rows like this: 
# (you may want to display this pattern in a fixed font for better legibility)

# P   A   H   N
# A P L S I I G
# Y   I   R
# And then read line by line: "PAHNAPLSIIGYIR"
# Write the code that will take a string and make this conversion given a number of rows:

# string convert(string text, int nRows);
# convert("PAYPALISHIRING", 3) should return "PAHNAPLSIIGYIR".

# python version: Python 3

__Author__ = 'BONFY'


class Solution:
    def convert(self, s, numRows):
        """
        :type s: str
        :type numRows: int
        :rtype: str
        """
        # f(n) = n + (n-2)
        if not s or len(s) == 0 or numRows <= 0:
            return ""
        if numRows == 1:
            return s
        if len(s) % (numRows + numRows - 2):
            s = s + '#' * (numRows + numRows - 2 - (len(s) % (numRows + numRows - 2)))
        blocks = len(s) // (numRows + numRows - 2)
        res = ''
        for i in range(numRows):
            for j in range(blocks):
                if i == 0 or i == numRows-1:
                    res += s[i + j*(numRows + numRows - 2)]
                else:
                    res += s[i + j*(numRows + numRows - 2)]
                    res += s[2*numRows-2-i + j*(numRows + numRows - 2)]
        return ''.join(res.split('#'))


class Solution2:
    def convert(self, s, nRows):
        step, zigzag = 2 * nRows - 2, ""
        if not s or len(s) == 0 or nRows <= 0:
            return ""
        if nRows == 1:
            return s
        for i in range(nRows):
            for j in range(i, len(s), step):
                zigzag += s[j]
                if i > 0 and i < nRows - 1 and j + step - 2 * i < len(s):
                    zigzag += s[j + step - 2 * i]
        return zigzag

if __name__ == '__main__':
    import time
    starttime = time.clock()
    print(Solution().convert("ABCDEFGHIJKLMN", 4))
    endtime = time.clock()
    print(endtime - starttime)


    starttime = time.clock()
    print(Solution2().convert("ABCDEFGHIJKLMN", 4))
    endtime = time.clock()
    print(endtime - starttime)
