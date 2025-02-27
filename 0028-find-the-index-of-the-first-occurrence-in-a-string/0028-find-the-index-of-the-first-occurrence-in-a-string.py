class Solution(object):
    def strStr(self, haystack, needle):
        """
        :type haystack: str
        :type needle: str
        :rtype: int
        """
        match = len(needle)
        n = len(haystack)
        for i in range(n):
            j = 0
            while i + j < n and haystack[i + j] == needle[j]:
                j += 1
                if j == match:
                    return i

        return -1