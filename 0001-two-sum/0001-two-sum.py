class Solution(object):
    def twoSum(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: List[int]
        """
        mapf = {}
        n = len(nums)
        for i in range(n):
            if nums[i] in mapf:
                return [mapf[nums[i]], i]
            mapf[target - nums[i]] = i
        
        return []
