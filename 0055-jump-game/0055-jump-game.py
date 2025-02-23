class Solution(object):
    def canJump(self, nums):
        """
        :type nums: List[int]
        :rtype: bool
        """
        step_on = len(nums)-1

        for i in range(len(nums)-2, -1, -1):
            if (nums[i] >= (step_on - i)):
                step_on = i

        return step_on == 0