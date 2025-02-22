class Solution(object):
    def merge(self, nums1, m, nums2, n):
        """
        :type nums1: List[int]
        :type m: int
        :type nums2: List[int]
        :type n: int
        :rtype: None Do not return anything, modify nums1 in-place instead.
        """
        nums3 = nums1[:]
        k, j = 0, 0
        for i in range(m+n):
            if j >= m or (k < n and nums3[j] > nums2[k]):
                nums1[i] = nums2[k]
                k += 1
            else:
                nums1[i] = nums3[j]
                j += 1
        