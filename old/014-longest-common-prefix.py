# -*-coding:utf-8-*-

# Write a function to find the longest common prefix string amongst an array of strings.

# python version: Python 3


__Auther__ = 'BONFY'


class Solution:
    def longestCommonPrefix(self, strs):
        """
        :type strs: List[str]
        :rtype: str
        """
        if not strs:
            return ""
        strs = sorted(strs, key=lambda str: len(str))
        idx, p, rest = 0, strs[0], strs[1:]
        while len(p) > 0:
            while idx < len(rest) and p == rest[idx][:len(p)]:
                idx += 1
            if idx == len(rest):
                return p
            p = p[:-1]
        return ""


# 少一步排序，更优
class Solution2:
    def longestCommonPrefix(self, strs):
        """
        :type strs: List[str]
        :rtype: str
        """
        if not strs:
            return ""
        if len(strs) == 1:
            return strs[0]
        idx, p, rest = 0, strs[0], strs[1:]
        while len(p) > 0:
            while idx < len(rest) and len(p) <= len(rest[idx]) and p == rest[idx][:len(p)]:
                idx += 1
            if idx == len(rest):
                return p
            p = p[:-1]
        return ""


if __name__ == '__main__':
    strs = ['abd', 'abc', 'abcd', 'abdcdss', 'aaaadss']
    import time
    start = time.clock()
    print(Solution().longestCommonPrefix(strs))
    end = time.clock()
    print(end-start)

    start = time.clock()
    print(Solution2().longestCommonPrefix(strs))
    end = time.clock()
    print(end-start)

