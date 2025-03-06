class Solution(object):
    def summaryRanges(self, nums):
        """
        :type nums: List[int]
        :rtype: List[str]
        """
        n = len(nums)
        i = 0
        ranges = []
        while i < n:
            start = i
            while i < n - 1 and nums[i+1] == nums[i] + 1:
                i += 1

            r = str(nums[start])
            if start != i:
                r += "->" + str(nums[i])
            ranges.append(r)
            i += 1
        return ranges