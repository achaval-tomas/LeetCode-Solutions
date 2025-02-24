class Solution(object):
    def jump(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        last_step = len(nums) - 1
        step_on = last_step
        candidate = last_step
        jump_count = 0

        i = last_step - 1
        while (i >= 0):
            # find longest step back from current step_on
            if (i + nums[i] >= step_on):
                candidate = i
                if i == 0: # if reached the start, just jump
                    return jump_count + 1

            # stop searching when we go too far or reach the start
            if (step_on - i > 1000 or i == 0):
                step_on = candidate
                jump_count += 1
                i = step_on
            else:
                i -= 1

        return jump_count