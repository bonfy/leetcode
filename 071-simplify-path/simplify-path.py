# -*- coding:utf-8 -*-


# Given an absolute path for a file (Unix-style), simplify it.
#
# For example,
# path = &quot;/home/&quot;, =&gt; &quot;/home&quot;
# path = &quot;/a/./b/../../c/&quot;, =&gt; &quot;/c&quot;
#
#
# click to show corner cases.
#
# Corner Cases:
#
#
#
# Did you consider the case where path = &quot;/../&quot;?
# In this case, you should return &quot;/&quot;.
# Another corner case is the path might contain multiple slashes &#39;/&#39; together, such as &quot;/home//foo/&quot;.
# In this case, you should ignore redundant slashes and return &quot;/home/foo&quot;.
#


class Solution(object):
    def simplifyPath(self, path):
        """
        :type path: str
        :rtype: str
        """
        # 思路：
        # 1. split / 形成List
        # 2. 如果 .. 就　pop 前面的
        # 3. 还要考虑　'///' '/...'
        places = [p for p in path.split("/") if p!="." and p!=""]
        stack = []
        for p in places:
            if p == "..":
                if len(stack) > 0:
                    stack.pop()
            else:
                stack.append(p)
        return "/" + "/".join(stack)
