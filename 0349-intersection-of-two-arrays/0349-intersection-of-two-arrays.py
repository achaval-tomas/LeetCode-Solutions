class Solution(object):
    def intersection(self, nums1, nums2):
        ans = []
        for i in nums1:
            if i in nums2 and i not in ans:
                ans.append(i)
        return ans
        