# -*-coding:utf-8-*-

# Given a string, find the length of the longest substring without repeating characters.

# Examples:

# Given "abcabcbb", the answer is "abc", which the length is 3.

# Given "bbbbb", the answer is "b", with the length of 1.

# Given "pwwkew", the answer is "wke", with the length of 3. Note that the answer must be a substring, "pwke" is a subsequence and not a substring.

# python version: Python 3

__Author__ = 'BONFY'


class Solution(object):
    def lengthOfLongestSubstring(self, s):
        """
        :type s: str
        :rtype: int
        """

        longest, start, visited = 0, 0, [False for _ in range(256)]
        for ind, val in enumerate(s):
            if not visited[ord(val)]:
                visited[ord(val)] = True
            else:
                while val != s[start]:
                    visited[ord(s[start])] = False
                    start += 1
                start += 1
            longest = max(longest, ind - start + 1)
        return longest


# I use an integer array T( len(T)= len(s)) to keep track of the length for the substring if the current character is just the end of the substring,
# and after one loop, the max number in the array is the answer we want.

# b p f b h m i p x
# 1
# 1 2
# 1 2 3
# 1 2 3 3
# for the second b, it should be 4 if there's no another b in the previous string, but it turns out there already exists b in the seq(bpf),
# and since b is in the position 1 of seq(bpf), the value for second b is 4 - 1 = 3, and make up a new seq(pfb) with length = 3

# b p f b h m i p x
# 1 2 3 3 4 5 6
# 1 2 3 3 4 5 6 6
# 1 2 3 3 4 5 6 6 7
# for the second p, it should be 7 if there's no another p in the previous string(pfbhmi),
# note that the previous seq is 'pfbhmi' due to the value for the previous characher 'i' is 6,
# and len('pfbhmi') = 6, but there's another 'p' in the previous seq, and the position for the 'p' is 1 in seq(pfbhmi),
# so the value for the second p is 7 - 1 = 6, which make it another seq(fbhmip) with length 6;

class Solution2(object):

    def lengthOfLongestSubstring(self, s):
        if not s:
            return 0
        T = [1] * len(s)
        for i in range(1, len(s)):
            T[i] = T[i - 1] - s[i - T[i - 1]:i].index(s[i]) if s[i] in s[i - T[i - 1]:i] else T[i - 1] + 1
        return max(T)


if __name__ == '__main__':
    print(Solution().lengthOfLongestSubstring("abcabcbb"))
    print(Solution().lengthOfLongestSubstring("abcabcdbb"))
    print(Solution().lengthOfLongestSubstring("pwwkew"))

    print(Solution2().lengthOfLongestSubstring("abcabcbb"))
    print(Solution2().lengthOfLongestSubstring("abcabcdbb"))
    print(Solution2().lengthOfLongestSubstring("pwwkew"))
