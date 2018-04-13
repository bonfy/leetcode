# -*- coding:utf-8 -*-


# Given an input string (s) and a pattern (p), implement regular expression matching with support for &#39;.&#39; and &#39;*&#39;.
#
#
# &#39;.&#39; Matches any single character.
# &#39;*&#39; Matches zero or more of the preceding element.
#
#
# The matching should cover the entire input string (not partial).
#
# Note:
#
#
# 	s&nbsp;could be empty and contains only lowercase letters a-z.
# 	p could be empty and contains only lowercase letters a-z, and characters like&nbsp;.&nbsp;or&nbsp;*.
#
#
# Example 1:
#
#
# Input:
# s = &quot;aa&quot;
# p = &quot;a&quot;
# Output: false
# Explanation: &quot;a&quot; does not match the entire string &quot;aa&quot;.
#
#
# Example 2:
#
#
# Input:
# s = &quot;aa&quot;
# p = &quot;a*&quot;
# Output: true
# Explanation:&nbsp;&#39;*&#39; means zero or more of the precedeng&nbsp;element, &#39;a&#39;. Therefore, by repeating &#39;a&#39; once, it becomes &quot;aa&quot;.
#
#
# Example 3:
#
#
# Input:
# s = &quot;ab&quot;
# p = &quot;.*&quot;
# Output: true
# Explanation:&nbsp;&quot;.*&quot; means &quot;zero or more (*) of any character (.)&quot;.
#
#
# Example 4:
#
#
# Input:
# s = &quot;aab&quot;
# p = &quot;c*a*b&quot;
# Output: true
# Explanation:&nbsp;c can be repeated 0 times, a can be repeated 1 time. Therefore it matches &quot;aab&quot;.
#
#
# Example 5:
#
#
# Input:
# s = &quot;mississippi&quot;
# p = &quot;mis*is*p*.&quot;
# Output: false
#
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
