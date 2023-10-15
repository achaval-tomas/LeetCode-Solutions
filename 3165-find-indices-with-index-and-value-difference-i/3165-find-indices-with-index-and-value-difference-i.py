class Solution(object):
    def findIndices(self, nums, indexDifference, valueDifference):
        for num in range(len(nums)):
            for num2 in range(num, len(nums)):
                if num2-num >= indexDifference and abs(nums[num]-nums[num2]) >= valueDifference:
                    return [num, num2]
        return [-1, -1]
        