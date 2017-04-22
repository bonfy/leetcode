# -*- coding:utf-8 -*-


# Say you have an array for which the ith element is the price of a given stock on day i.
#
# Design an algorithm to find the maximum profit. You may complete as many transactions as you like (ie, buy one and sell one share of the stock multiple times). However, you may not engage in multiple transactions at the same time (ie, you must sell the stock before you buy again).


class Solution(object):
    def maxProfit(self, prices):
        """
        :type prices: List[int]
        :rtype: int
        """
        profit = 0
        tmp_profit = 0
        if not prices:
            return profit
        cur = prices[0]
        for item in prices[1:]:
            if item >= cur:
                tmp_profit = tmp_profit+item-cur
            else:
                profit += tmp_profit
                tmp_profit = 0
            cur = item
        profit += tmp_profit
        return profit
