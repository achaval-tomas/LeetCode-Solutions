class Solution(object):
    def lengthOfLastWord(self, s):
        """
        :type s: str
        :rtype: int
        """
        i = len(s)-1
        while (i >= 0 and s[i] == ' '):
            i -= 1
        
        end = i
        while (i >= 0 and s[i] != ' '):
            i -= 1
        start = i

        return end - start