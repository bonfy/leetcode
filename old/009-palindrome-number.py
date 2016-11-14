# -*-coding:utf-8-*-

# Determine whether an integer is a palindrome. Do this without extra space.

# click to show spoilers.

# Some hints:
# Could negative integers be palindromes? (ie, -1)

# If you are thinking of converting the integer to string, note the restriction of using extra space.

# You could also try reversing an integer. However, if you have solved the problem "Reverse Integer",
# you know that the reversed integer might overflow. How would you handle such case?

# There is a more generic way of solving this problem.


# python version: Python 3

__Author__ = 'BONFY'


class Solution:
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
        while i < l // 2 + 1:

            head = (x // 10 ** (l-i)) % 10
            tail = (x % 10 ** i) if i == 1 else (x % 10 ** i) // (10 ** (i-1))
            if head != tail:
                return False
            i = i + 1

        return True


if __name__ == '__main__':
    print(Solution().isPalindrome(10011001))
