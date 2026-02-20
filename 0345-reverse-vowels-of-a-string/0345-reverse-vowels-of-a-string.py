class Solution(object):
    def reverseVowels(self, s):
        """
        :type s: str
        :rtype: str
        """
        vowels = "aeiouAEIOU"
        vowStr = [char for char in s if char in vowels]

        i = 0
        v = len(vowStr) - 1
        revStr = ""
        for i in range(len(s)):
            if s[i] in vowels:
                revStr += vowStr[v]
                v -= 1
            else:
                revStr += s[i]

        return revStr
        