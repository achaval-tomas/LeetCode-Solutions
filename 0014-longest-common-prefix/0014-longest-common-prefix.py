class Solution(object):
    def longestCommonPrefix(self, strs):
        """
        :type strs: List[str]
        :rtype: str
        """
        word1 = strs[0]
        w1_len = len(word1)
        wc = len(strs)

        for i in range(w1_len):
            c = word1[i]
            for j in range(wc):
                if len(strs[j]) <= i or strs[j][i] != c:
                    return word1[:i]
            
        return ""

            