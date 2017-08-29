# -*- coding:utf-8 -*-


# Given a string containing just the characters &#39;(&#39;, &#39;)&#39;, &#39;{&#39;, &#39;}&#39;, &#39;[&#39; and &#39;]&#39;, determine if the input string is valid.
#
# The brackets must close in the correct order, &quot;()&quot; and &quot;()[]{}&quot; are all valid but &quot;(]&quot; and &quot;([)]&quot; are not.


class Solution(object):
    def isValid(self, s):
        """
        :type s: str
        :rtype: bool
        """
        pattern = {
            '(': ')',
            '{': '}',
            '[': ']'
            }
        lst = []
        end = None
        for item in s:
            if item in list(pattern.keys()):
                lst.append(item)
                end = item
            # elif end == None: # 起手是value 的情况
            #    return False
            elif end and pattern[end] == item:
                lst.pop()
                end = lst[-1] if lst else None
            else:
                return False
        return len(lst)==0
