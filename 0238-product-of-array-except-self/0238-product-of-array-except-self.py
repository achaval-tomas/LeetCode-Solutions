class Solution(object):
    def productExceptSelf(self, nums):
        """
        :type nums: List[int]
        :rtype: List[int]
        """
        length = len(nums)
        prefixes = [n for n in nums]
        suffixes = [n for n in nums]
        for i in range(1, length - 1):
            prefixes[i] *= prefixes[i - 1]
            suffixes[length - 1 - i] *= suffixes[length - 1 - i + 1]
        
        prefixes[length - 1] *= prefixes[length - 2]
        
        answer = [1 for _ in range(length)]
        for i in range(length):
            if i > 0:
                answer[i] *= prefixes[i-1]
            if i < length - 1:
                answer[i] *= suffixes[i+1]

        return answer