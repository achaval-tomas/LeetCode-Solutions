class Solution(object):
    def longestCommonPrefix(self, strs):
        """
        :type strs: List[str]
        :rtype: str
        """
        word1 = strs[0]
        max_match = len(word1)
        for i in range(1, len(strs)):
            j = 0
            check_amount = min(len(strs[i]), max_match)
            while j < check_amount and strs[i][j] == word1[j]:
                j += 1
            max_match = min(max_match, j)
        return word1[:max_match]

            