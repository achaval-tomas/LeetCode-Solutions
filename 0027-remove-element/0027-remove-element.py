class Solution(object):
    def removeElement(self, nums, val):
        """
        :type nums: List[int]
        :type val: int
        :rtype: int
        """
        n = len(nums)
        k = 0
        for i in range(n):
            if nums[i] == val:
                continue
            nums[k] = nums[i]
            k += 1
        
        return k