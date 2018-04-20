# -*- coding:utf-8 -*-


# Determine whether an integer is a palindrome. An integer is a palindrome when it reads the same backward as forward.
#
# Example 1:
#
#
# Input: 121
# Output: true
#
#
# Example 2:
#
#
# Input: -121
# Output: false
# Explanation: From left to right, it reads -121. From right to left, it becomes 121-. Therefore it is not a palindrome.
#
#
# Example 3:
#
#
# Input: 10
# Output: false
# Explanation: Reads 01 from right to left. Therefore it is not a palindrome.
#
#
# Follow up:
#
# Coud you solve it without converting the integer to a string?
#


class Solution(object):
    def isPalindrome(self, x):
        """
        :type x: int
        :rtype: bool
        """
        if x < 0:
            return False
        x = abs(x)
        l = len(str(x))
        i = 1
        while i < l / 2 + 1:

            head = (x / 10 ** (l-i)) % 10
            tail = (x % 10 ** i) if i == 1 else (x % 10 ** i) / (10 ** (i-1))
            if head != tail:
                return False
            i = i + 1

        return True
