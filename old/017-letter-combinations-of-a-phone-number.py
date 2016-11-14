# -*-coding:utf-8-*-

# Given a digit string, return all possible letter combinations that the number could represent.

# A mapping of digit to letters (just like on the telephone buttons) is given below.

# 2 - abc
# 3 - efg
# 4 - ghi
# 5 - jkl
# 6 - mno
# 7 - pqrs
# 8 - tuv
# 9 - wxyz

# Input:Digit string "23"
# Output: ["ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"].


# python version: Python 3

__Author = 'BONFY'


class Solution:
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


# Python 2.7 reduce
# one line solution
class Solution2:
    def letterCombinations(self, digits):
        if '' == digits:
            return []
        kvmaps = {
            '2': 'abc',
            '3': 'def',
            '4': 'ghi',
            '5': 'jkl',
            '6': 'mno',
            '7': 'pqrs',
            '8': 'tuv',
            '9': 'wxyz'
        }
        return reduce(lambda acc, digit: [x + y for x in acc for y in kvmaps[digit]], digits, [''])

if __name__ == '__main__':
    print(Solution2().letterCombinations('23'))
