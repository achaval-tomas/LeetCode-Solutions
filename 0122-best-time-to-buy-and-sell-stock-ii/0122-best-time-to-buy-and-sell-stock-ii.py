class Solution(object):
    def maxProfit(self, prices):
        """
        :type prices: List[int]
        :rtype: int
        """
        max_profit = 0
        buy = 0
        for i in range(len(prices) - 1):
            if prices[i] < prices[i+1]:
                # prices keep going up
                continue
            else:
                # sell today and buy tomorrow
                max_profit += prices[i] - prices[buy]
                buy = i+1

        if buy != len(prices) - 1:
            # sell everything last day
            max_profit += prices[len(prices) - 1] - prices[buy]

        return max_profit