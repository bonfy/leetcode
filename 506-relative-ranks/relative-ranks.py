# -*- coding:utf-8 -*-


#
# Given scores of N athletes, find their relative ranks and the people with the top three highest scores, who will be awarded medals: &quot;Gold Medal&quot;, &quot;Silver Medal&quot; and &quot;Bronze Medal&quot;.
#
# Example 1:
#
# Input: [5, 4, 3, 2, 1]
# Output: [&quot;Gold Medal&quot;, &quot;Silver Medal&quot;, &quot;Bronze Medal&quot;, &quot;4&quot;, &quot;5&quot;]
# Explanation: The first three athletes got the top three highest scores, so they got &quot;Gold Medal&quot;, &quot;Silver Medal&quot; and &quot;Bronze Medal&quot;. For the left two athletes, you just need to output their relative ranks according to their scores.
#
#
#
# Note:
#
# N is a positive integer and won&#39;t exceed 10,000.
# All the scores of athletes are guaranteed to be unique.
#
#


class Solution(object):
    def findRelativeRanks(self, nums):
        """
        :type nums: List[int]
        :rtype: List[str]
        """
        result = [str(i) for i in nums]
        ranks = [(idx, val) for idx, val in enumerate(nums)]
        ranks.sort(key=lambda k: k[1], reverse=True)
        
        for idx, val in enumerate(ranks):
            if idx == 0:
                result[val[0]] = 'Gold Medal'
            elif idx == 1:
                result[val[0]] = 'Silver Medal'
            elif idx == 2:
                result[val[0]] = 'Bronze Medal'
            else:
                result[val[0]] = str(idx+1)
        return result
            
            
        
