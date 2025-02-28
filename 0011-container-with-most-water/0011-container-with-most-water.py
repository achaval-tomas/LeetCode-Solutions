class Solution(object):
    def maxArea(self, height):
        """
        :type height: List[int]
        :rtype: int
        """
        max_area = 0
        i = 0
        j = len(height) - 1
        while (i < j):
            max_area = max(max_area, (j-i)*min(height[j], height[i]))
            if height[i] <= height[j]:
                i += 1
            elif height[j] <= height[i]:
                j -= 1
        return max_area