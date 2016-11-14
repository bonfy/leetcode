# -*-coding:utf-8-*-

# Given a string, determine if it is a palindrome, considering only alphanumeric characters and ignoring cases.

# For example,
# "A man, a plan, a canal: Panama" is a palindrome.
# "race a car" is not a palindrome.

# Note:
# Have you consider that the string might be empty? This is a good question to ask during an interview.

# For the purpose of this problem, we define empty string as valid palindrome.

# python version: Python 3


# Solution TLE :  Time Limit Exceeded
class Solution:
    def isPalindrome(self, s):
        """
        :type s: str
        :rtype: bool
        """
        words = 'abcdefghijklmnopqrstuvwxyz0123456789'
        s_clean = ''
        for _, w in enumerate(s):
            if w.lower() in words:
                s_clean += w.lower()
        s_reverse = ''.join(list(s_clean)[::-1])
        return s_clean == s_reverse


# Solution :GOOD
class Solution2:
    def isPalindrome(self, s):
        """
        :type s: str
        :rtype: bool
        """
        s = filter(str.isalnum, str(s.lower()))
        return s == s[::-1]


if __name__ == '__main__':
	print(Solution2().isPalindrome('A man, a plan, a canal: Panama'))
