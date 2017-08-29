# -*- coding:utf-8 -*-


# Given an absolute path for a file (Unix-style), simplify it.
#
# For example,
# path = "/home/", =&gt; "/home"
# path = "/a/./b/../../c/", =&gt; "/c"
#
#
# click to show corner cases.
#
# Corner Cases:
#
#
#
# Did you consider the case where path = "/../"?
# In this case, you should return "/".
# Another corner case is the path might contain multiple slashes &#39;/&#39; together, such as "/home//foo/".
# In this case, you should ignore redundant slashes and return "/home/foo".
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
