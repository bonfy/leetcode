# -*- coding:utf-8 -*-


# Given a string containing only digits, restore it by returning all possible valid IP address combinations.
#
# Example:
#
#
# Input: "25525511135"
# Output: ["255.255.11.135", "255.255.111.35"]
#
#


class Solution(object):
    def restoreIpAddresses(self, s):
        """
        :type s: str
        :rtype: List[str]
        """
        ans = []
        self.helper(ans, s, 4, [])
        return ['.'.join(x) for x in ans]
        
    def helper(self, ans, s, k, temp):
        if len(s) > k*3:
            return
        if k == 0:
            ans.append(temp[:])
        else:
            for i in range(min(3,len(s)-k+1)):
                if i==2 and int(s[:3]) > 255 or i > 0 and s[0] == '0':
                    continue
                self.helper(ans, s[i+1:], k-1, temp+[s[:i+1]])
