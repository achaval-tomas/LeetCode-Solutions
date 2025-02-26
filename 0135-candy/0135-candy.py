class Solution(object):
    def candy(self, ratings):
        """
        :type ratings: List[int]
        :rtype: int
        """
        n = len(ratings)
        candies = [1 for _ in range(n)]

        for i in range(n-1):
            if (ratings[i+1] > ratings[i]):
                candies[i+1] = candies[i] + 1

        for i in range(n-1, 0, -1):
            if (ratings[i-1] > ratings[i] and candies[i-1] <= candies[i]):
                candies[i-1] = candies[i] + 1

        return sum(candies)