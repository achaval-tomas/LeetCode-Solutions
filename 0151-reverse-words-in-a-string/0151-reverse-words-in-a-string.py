class Solution(object):
    def reverseWords(self, s):
        """
        :type s: str
        :rtype: str
        """
        n = len(s)
        res = ""

        i = 0
        while (i < n):
            if s[i] == ' ':
                i += 1
                continue
            word = ""
            while (i < n and s[i] != ' '):
                word += s[i]
                i += 1
            res = word + ' ' + res

        return res[:len(res)-1]