# -*- coding:utf-8 -*-


#
# There are N gas stations along a circular route, where the amount of gas at station i is gas[i].
#
#
#
# You have a car with an unlimited gas tank and it costs cost[i] of gas to travel from station i to its next station (i+1). You begin the journey with an empty tank at one of the gas stations.
#
#
#
# Return the starting gas station&#39;s index if you can travel around the circuit once, otherwise return -1.
#
#
#
# Note:
# The solution is guaranteed to be unique.


class Solution(object):
    def canCompleteCircuit(self, gas, cost):
        """
        :type gas: List[int]
        :type cost: List[int]
        :rtype: int
        """
        if len(gas) == 0 or len(cost) == 0 or sum(gas) < sum(cost):
            return -1
        position = 0
        balance = 0 # current tank balance
        for i in range(len(gas)):
            balance += gas[i] - cost[i] # update balance
            if balance < 0: # balance drops to negative, reset the start position
                balance = 0
                position = i+1
        return position
