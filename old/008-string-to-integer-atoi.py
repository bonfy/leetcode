# -*-coding:utf-8-*-

# Implement atoi to convert a string to an integer.

# Hint: Carefully consider all possible input cases.
# If you want a challenge, please do not see below and ask yourself what are the possible input cases.

# Notes: It is intended for this problem to be specified vaguely
# (ie, no given input specs). You are responsible to gather all the input requirements up front.

# python version: Python 3

__Author__ = 'BONFY'


class Solution:
    def myAtoi(self, str):
        """
        :type str: str
        :rtype: int
        """
        import re
        p = re.compile(r'^[+-]?[0-9]+')
        m = re.match(p, str.strip())
        if m:
            ret = int(m.group())
            if ret < -0x80000000:
                return -0x80000000
            elif ret > 0x7fffffff:
                return 0x7fffffff
            return ret
        else:
            return 0


if __name__ == '__main__':
    print(Solution().myAtoi('1234'))
