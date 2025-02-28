class Solution(object):
    def isSubsequence(self, s, t):
        """
        :type s: str
        :type t: str
        :rtype: bool
        """
        check, limit, c, t_len = 0, len(s), 0, len(t)
        while (check < limit and c < t_len):
            if t[c] == s[check]:
                check += 1
            c += 1

        return check == limit