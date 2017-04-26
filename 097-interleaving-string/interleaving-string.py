# -*- coding:utf-8 -*-


# Given s1, s2, s3, find whether s3 is formed by the interleaving of s1 and s2.
#
#
#
# For example,
# Given:
# s1 = "aabcc",
# s2 = "dbbca",
#
#
# When s3 = "aadbbcbcac", return true.
# When s3 = "aadbbbaccc", return false.


class Solution(object):
    def isInterleave(self, s1, s2, s3):
        """
        :type s1: str
        :type s2: str
        :type s3: str
        :rtype: bool
        """
        
        r, c, l= len(s1), len(s2), len(s3)
        if r+c != l:
            return False
        stack, visited = [(0, 0)], set((0, 0))
        while stack:
            x, y = stack.pop()
            if x+y == l:
                return True
            if x+1 <= r and s1[x] == s3[x+y] and (x+1, y) not in visited:
                stack.append((x+1, y)); visited.add((x+1, y))
            if y+1 <= c and s2[y] == s3[x+y] and (x, y+1) not in visited:
                stack.append((x, y+1)); visited.add((x, y+1))
        return False
