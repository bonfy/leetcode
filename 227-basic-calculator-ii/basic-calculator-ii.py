# -*- coding:utf-8 -*-


# Implement a basic calculator to evaluate a simple expression string.
#
# The expression string contains only non-negative integers, +, -, *, / operators and empty spaces  . The integer division should truncate toward zero.
#
# You may assume that the given expression is always valid.
#
# Some examples:
#
# "3+2*2" = 7
# " 3/2 " = 1
# " 3+5 / 2 " = 5
#
#
#
#
# Note: Do not use the eval built-in library function.
#
#
# Credits:Special thanks to @ts for adding this problem and creating all test cases.


class Solution(object):
    def calculate(self, s):
        """
        :type s: str
        :rtype: int
        """
        if not s:
            return 0
        stack, num ,sign= [], 0, '+'
        for i in xrange(len(s)):
            if s[i].isdigit():
                num = num*10+ord(s[i])-ord('0')
            if (not s[i].isdigit() and not s[i].isspace()) or i == len(s)-1:
                if sign == '-':
                    stack.append(-num)
                elif sign == '+':
                    stack.append(num)
                elif sign == '*':
                    stack.append(stack.pop()*num)
                else:
                    tmp = stack.pop()
                    if tmp < 0 and abs(tmp)%num != 0:
                        stack.append(tmp/num+1)
                    else:
                        stack.append(tmp/num)
                sign = s[i]
                num = 0
        return sum(stack)
