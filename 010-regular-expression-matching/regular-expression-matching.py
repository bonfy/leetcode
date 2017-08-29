# -*- coding:utf-8 -*-


# Implement regular expression matching with support for &#39;.&#39; and &#39;*&#39;.
#
#
# &#39;.&#39; Matches any single character.
# &#39;*&#39; Matches zero or more of the preceding element.
#
# The matching should cover the entire input string (not partial).
#
# The function prototype should be:
# bool isMatch(const char *s, const char *p)
#
# Some examples:
# isMatch(&quot;aa&quot;,&quot;a&quot;) &amp;rarr; false
# isMatch(&quot;aa&quot;,&quot;aa&quot;) &amp;rarr; true
# isMatch(&quot;aaa&quot;,&quot;aa&quot;) &amp;rarr; false
# isMatch(&quot;aa&quot;, &quot;a*&quot;) &amp;rarr; true
# isMatch(&quot;aa&quot;, &quot;.*&quot;) &amp;rarr; true
# isMatch(&quot;ab&quot;, &quot;.*&quot;) &amp;rarr; true
# isMatch(&quot;aab&quot;, &quot;c*a*b&quot;) &amp;rarr; true


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
