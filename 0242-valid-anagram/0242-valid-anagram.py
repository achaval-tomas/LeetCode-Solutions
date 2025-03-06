class Solution(object):
    def isAnagram(self, s, t):
        """
        :type s: str
        :type t: str
        :rtype: bool
        """
        check = {}
        for c in s:
            check.setdefault(c, 0)
            check[c] += 1

        for c in t:
            if c not in check or check[c] == 0:
                return False
            check[c] -= 1

        return all(c == 0 for c in check.values())