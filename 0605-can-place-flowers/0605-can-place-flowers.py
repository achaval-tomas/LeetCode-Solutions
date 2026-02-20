class Solution(object):
    def canPlaceFlowers(self, flowerbed, n):
        """
        :type flowerbed: List[int]
        :type n: int
        :rtype: bool
        """
        x = n

        if sum(flowerbed[:2]) == 0:
            flowerbed[0] = 1
            x -= 1
        if sum(flowerbed[-2:]) == 0:
            flowerbed[-1] = 1
            x -= 1

        for i in range(len(flowerbed)-3):
            if sum(flowerbed[i:i+3]) == 0:
                flowerbed[i+1] = 1
                x -= 1

        return x <= 0