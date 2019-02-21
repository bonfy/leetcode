# -*- coding:utf-8 -*-


# There are 1000 buckets, one and only one of them contains poison, the rest are filled with water. They all look the same. If a pig drinks that poison it will die within 15 minutes. What is the minimum amount of pigs you need to figure out which bucket contains the poison within one hour.
#
# Answer this question, and write an algorithm for the follow-up general case.
#
# Follow-up: 
#
# If there are n buckets and a pig drinking poison will die within m minutes, how many pigs (x) you need to figure out the "poison" bucket within p minutes? There is exact one bucket with poison.
#


class Solution(object):
    def poorPigs(self, buckets, minutesToDie, minutesToTest):
        """
        :type buckets: int
        :type minutesToDie: int
        :type minutesToTest: int
        :rtype: int
        """
        # corner case
        if buckets == 1:
            return 0
        if minutesToTest // minutesToDie <= 1:
            return buckets - 1
        # general case: just get the n in n^(test_times + 1) = buckets
        return int(math.ceil(math.log(buckets, (minutesToTest // minutesToDie) + 1)))
