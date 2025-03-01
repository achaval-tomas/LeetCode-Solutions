class Solution(object):
    def threeSum(self, nums):
        """
        :type nums: List[int]
        :rtype: List[List[int]]
        """
        nums.sort()
        n = len(nums)
        triplets = set()
        for i in range(n):
            if nums[i] > 0:
                break

            j = i+1
            k = n-1
            target = -1 * nums[i]

            while (j < k):
                if nums[j] + nums[k] > target:
                    k -= 1
                elif nums[j] + nums[k] < target:
                    j += 1
                else:
                    triplets.add((nums[i], nums[j], nums[k]))
                    j += 1
                    k -= 1

        return list(triplets)
                