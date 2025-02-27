class Solution(object):
    def isPalindrome(self, s):
        """
        :type s: str
        :rtype: bool
        """
        alph = "abcdefghijklmnopqrstuvwxyz0123456789"
        s = s.lower()
        s = [c for c in s if c in alph]
        i, j = 0, len(s) - 1
        while (i < j):
            if s[i] != s[j]:
                return False
            i += 1
            j -= 1
        return True