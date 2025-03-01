class Solution(object):
    def minSubArrayLen(self, target, nums):
        """
        :type target: int
        :type nums: List[int]
        :rtype: int
        """
        n = len(nums)
        i, j = 0, 1
        total = nums[i]
        if total >= target:
            return 1

        shortest = n + 1

        while (i < j < n):
            while j < n and total < target:
                total += nums[j]
                j += 1

            while i < j and total >= target:
                shortest = min(shortest, j - i)
                total -= nums[i]
                i += 1

        return shortest if shortest <= n else 0
