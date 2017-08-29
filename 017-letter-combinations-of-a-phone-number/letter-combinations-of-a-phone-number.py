# -*- coding:utf-8 -*-


# Given a digit string, return all possible letter combinations that the number could represent.
#
#
#
# A mapping of digit to letters (just like on the telephone buttons) is given below.
#
#
#
# Input:Digit string &quot;23&quot;
# Output: [&quot;ad&quot;, &quot;ae&quot;, &quot;af&quot;, &quot;bd&quot;, &quot;be&quot;, &quot;bf&quot;, &quot;cd&quot;, &quot;ce&quot;, &quot;cf&quot;].
#
#
#
# Note:
# Although the above answer is in lexicographical order, your answer could be in any order you want.


class Solution(object):
    def letterCombinations(self, digits):
        """
        :type digits: str
        :rtype: List[str]
        """
        l = ['', '', 'abc', 'def', 'ghi', 'jkl', 'mno', 'pqrs', 'tuv', 'wxyz']
        end = ['']
        rst = []
        d = digits

        while len(d):
            f = int(d[-1])
            lst_f = list(l[f])
            rst = [''.join([i, j]) for i in lst_f for j in end]
            end = rst
            d = d[:-1]
        return rst

