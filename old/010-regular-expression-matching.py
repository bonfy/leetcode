# -*-coding:utf-8-*-

# Implement regular expression matching with support for '.' and '*'.

# '.' Matches any single character.
# '*' Matches zero or more of the preceding element.

# The matching should cover the entire input string (not partial).

# The function prototype should be:
# bool isMatch(const char *s, const char *p)

# Some examples:
# isMatch("aa","a") → false
# isMatch("aa","aa") → true
# isMatch("aaa","aa") → false
# isMatch("aa", "a*") → true
# isMatch("aa", ".*") → true
# isMatch("ab", ".*") → true
# isMatch("aab", "c*a*b") → true

__Auther__ = 'BONFY'


class Solution:
    def isMatch(self, s, p):
        """
        :type s: str
        :type p: str
        :rtype: bool
        """
        result = [[False for _ in range(len(p) + 1)] for _ in range(len(s) + 1)]

        result[0][0] = True
        for i in range(2, len(p) + 1):
            if p[i-1] == '*':
                result[0][i] = result[0][i-2]

        for i in range(1, len(s) + 1):
            for j in range(1, len(p) + 1):
                if p[j-1] != '*':
                    result[i][j] = result[i-1][j-1] and (s[i-1] == p[j-1] or p[j-1] == '.')
                else:
                    result[i][j] = result[i][j-2] or (result[i-1][j] and (s[i-1] == p[j-2] or p[j-2] == '.'))

        return result[len(s)][len(p)]


if __name__ == '__main__':
    print(Solution().isMatch("aab", "c.a.b"))
    print(Solution().isMatch("ab", ".*"))
    print(Solution().isMatch("aab", "a*b"))
    print(Solution().isMatch("aab", "b*b"))
