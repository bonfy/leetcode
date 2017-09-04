# -*- coding:utf-8 -*-


# Implement regular expression matching with support for '.' and '*'.
#
#
# '.' Matches any single character.
# '*' Matches zero or more of the preceding element.
#
# The matching should cover the entire input string (not partial).
#
# The function prototype should be:
# bool isMatch(const char *s, const char *p)
#
# Some examples:
# isMatch("aa","a") &rarr; false
# isMatch("aa","aa") &rarr; true
# isMatch("aaa","aa") &rarr; false
# isMatch("aa", "a*") &rarr; true
# isMatch("aa", ".*") &rarr; true
# isMatch("ab", ".*") &rarr; true
# isMatch("aab", "c*a*b") &rarr; true
#


class Solution(object):
    def isMatch(self, s, p):
        """
        :type s: str
        :type p: str
        :rtype: bool
        """
        result = [[False for j in xrange(len(p) + 1)] for i in xrange(len(s) + 1)]
        
        result[0][0] = True
        for i in xrange(2, len(p) + 1):
            if p[i-1] == '*':
                result[0][i] = result[0][i-2]
                    
        for i in xrange(1,len(s) + 1):
            for j in xrange(1, len(p) + 1):
                if p[j-1] != '*':
                    result[i][j] = result[i-1][j-1] and (s[i-1] == p[j-1] or p[j-1] == '.')
                else:
                    result[i][j] = result[i][j-2] or (result[i-1][j] and (s[i-1] == p[j-2] or p[j-2] == '.'))
                    
        return result[len(s)][len(p)]
