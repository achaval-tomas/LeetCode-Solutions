class Solution(object):
    def longestCommonPrefix(self, strs):
        """
        :type strs: List[str]
        :rtype: str
        """
        word1 = strs[0]
        max_len = min(len(w) for w in strs)
        wc = len(strs)

        for i in range(max_len):
            c = word1[i]
            for j in range(wc):
                if strs[j][i] != c:
                    return word1[:i]
            if i == max_len - 1:
                return word1[:max_len]

        return ""

            