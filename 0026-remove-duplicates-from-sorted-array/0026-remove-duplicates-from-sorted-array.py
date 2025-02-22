class Solution(object):
    def removeDuplicates(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        k = 0
        n = len(nums)
        for i in range(n):
            if i+1 < n and nums[i] == nums[i+1]:
                continue
            nums[k] = nums[i]
            k += 1
        return k