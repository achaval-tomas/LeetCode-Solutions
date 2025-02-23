class Solution(object):
    def maxProfit(self, prices):
        """
        :type prices: List[int]
        :rtype: int
        """
        buy = 0
        sell = 1
        max_profit = 0
        for i in range(len(prices)):
            if prices[i] < prices[buy]:
                buy = i
            elif prices[i] - prices[buy] > max_profit:
                sell = i
                max_profit = prices[sell] - prices[buy]
        return max_profit