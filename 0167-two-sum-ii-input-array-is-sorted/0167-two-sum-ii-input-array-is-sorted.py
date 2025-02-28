class Solution(object):
    def twoSum(self, numbers, target):
        """
        :type numbers: List[int]
        :type target: int
        :rtype: List[int]
        """
        l = 0
        r = len(numbers) - 1
        
        while (l < r):
            val = numbers[l] + numbers[r]
            if val > target:
                r -= 1
            elif val < target:
                l += 1
            else:
                break
        return [l+1, r+1]
        
