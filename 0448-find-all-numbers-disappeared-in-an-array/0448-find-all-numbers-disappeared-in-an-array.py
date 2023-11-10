class Solution(object):
    def findDisappearedNumbers(self, nums):
        ans = []
        length = len(nums)

        for i in range(length):
            nums[abs(nums[i])-1] = -abs(nums[abs(nums[i])-1])

        for i in range(length):
            if nums[i] > 0:
                ans.append(i+1)

        return ans