class Solution(object):
    def mergeAlternately(self, word1, word2):
        """
        :type word1: str
        :type word2: str
        :rtype: str
        """
        i = 0
        l1 = len(word1)
        l2 = len(word2)
        res = ""
        while i < min(l1, l2):
            res += word1[i] + word2[i]
            i += 1

        res += word1[i:] + word2[i:]
        return res