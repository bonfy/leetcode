# -*-coding:utf-8-*-

# Given a string S, find the longest palindromic substring in S.
# You may assume that the maximum length of S is 1000,
# and there exists one unique longest palindromic substring.

# python version: Python 3

__Author__ = 'BONFY'


class Solution:
    def longestPalindrome(self, s):
        """
        :type s: str
        :rtype: str
        """
        longest, mid = "", (len(s) - 1) // 2
        i, j = mid, mid
        while i >= 0 and j < len(s):
            args = [(s, i, i), (s, i, i + 1), (s, j, j), (s, j, j + 1)]
            for arg in args:
                tmp = self.longestPalindromeByAxis(*arg)
                if len(tmp) > len(longest):
                    longest = tmp
            if len(longest) >= i * 2:

                # leetcode 回文字符串长度为1 时要求返回第一个字母
                # 加上后两句
                if len(longest) == 1:
                    return s[0]

                return longest
            i, j = i - 1, j + 1
        return longest

    def longestPalindromeByAxis(self, s, left, right):
        while left >= 0 and right < len(s) and s[left] == s[right]:
            left, right = left - 1, right + 1
        return s[left + 1: right]


if __name__ == '__main__':
    print(Solution().longestPalindrome('abcdefghgfedasd'))
