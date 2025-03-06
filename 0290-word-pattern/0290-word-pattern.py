class Solution(object):
    def wordPattern(self, pattern, s):
        """
        :type pattern: str
        :type s: str
        :rtype: bool
        """
        mapf = {}
        n = len(s)
        i = 0

        for c in pattern:
            word = ""
            while i < n and s[i] != " ":
                word += s[i]
                i += 1
            
            if c in mapf:
                if mapf[c] != word:
                    return False              
            elif word not in mapf.values():
                mapf[c] = word
            else:
                return False
            
            i += 1

        return i == n + 1
        