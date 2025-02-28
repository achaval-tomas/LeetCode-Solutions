class Solution(object):
    def isSubsequence(self, s, t):
        """
        :type s: str
        :type t: str
        :rtype: bool
        """
        check = 0
        for c in t:
            if check < len(s) and c == s[check]:
                check += 1
            elif check == len(s):
                return True
        return check == len(s)