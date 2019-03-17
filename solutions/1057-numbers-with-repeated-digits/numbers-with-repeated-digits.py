# Given a positive integer N, return the number of positive integers less than or equal to N that have at least 1 repeated digit.
#
#  
#
#
# Example 1:
#
#
# Input: 20
# Output: 1
# Explanation: The only positive number (<= 20) with at least 1 repeated digit is 11.
#
#
#
# Example 2:
#
#
# Input: 100
# Output: 10
# Explanation: The positive numbers (<= 100) with atleast 1 repeated digit are 11, 22, 33, 44, 55, 66, 77, 88, 99, and 100.
#
#
#
# Example 3:
#
#
# Input: 1000
# Output: 262
#
#
#
#  
#
# Note:
#
#
# 	1 <= N <= 10^9
#
#
#
#


class Solution:
    def numDupDigitsAtMostN(self, N: int) -> int:
        from math import factorial
        def noRep(dgt, i):
            if i == len(dgt):
                return True
            while dgt[i] in dgt[:i] or not noRep(dgt, i + 1):
                dgt[i] -= 1
                for j in range(i + 1, len(dgt)):
                    dgt[j] = 9
                if dgt[i] < 0:
                    dgt[i] = 9
                    return False
            return True
        def lastCounted(n):
            dgt = [int(i) for i in str(n - 1)]
            while not noRep(dgt, 0):
                dgt = [9]*(len(dgt) - 1)
            while dgt[0] == 0:
                dgt = dgt[1:]
            return dgt
        def cntNoRep(n):
            if n < 2:
                return 0
            dgt = lastCounted(n)
            def forLength(length, numdgt, numFirst):
                return numFirst * (factorial(numdgt - 1) / factorial(numdgt - length))
            cnt = 1
            l = len(dgt)
            for i in range(1, l):
                cnt += forLength(i, 10, 9)
            firstdgt = set(range(10))
            for i, d in enumerate(dgt):
                firstCur = firstdgt & set(range(d))
                if i == 0:
                    firstCur.discard(0)
                cnt += forLength(l - i, 10 - i, len(firstCur))
                firstdgt.discard(d)
            return cnt
        return int(N - cntNoRep(N + 1))

