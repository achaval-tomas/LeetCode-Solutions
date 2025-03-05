class Solution(object):
    def isIsomorphic(self, s, t):
        """
        :type s: str
        :type t: str
        :rtype: bool
        """
        mapf = {}
        n = len(s)
        for i in range(n):
            if s[i] in mapf:
                if t[i] != mapf[s[i]]:
                    return False
            elif t[i] not in mapf.values():
                mapf[s[i]] = t[i]
            else:
                return False
        return True
        