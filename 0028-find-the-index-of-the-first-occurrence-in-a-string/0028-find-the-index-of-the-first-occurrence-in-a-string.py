class Solution(object):
    def strStr(self, haystack, needle):
        """
        :type haystack: str
        :type needle: str
        :rtype: int
        """
        match = len(needle)
        i, n = 0, len(haystack)
        while i < n:
            next_i = i+1
            j = 0
            found = False
            while i + j < n and haystack[i + j] == needle[j]:
                j += 1
                if j == match:
                    return i
                elif i+j < n and haystack[i+j] == needle[0] and not found:
                    next_i = i + j
                    found = True
            i = next_i

        return -1