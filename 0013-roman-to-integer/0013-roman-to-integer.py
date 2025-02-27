class Solution(object):
    def romanToInt(self, s):
        """
        :type s: str
        :rtype: int
        """
        roman = {
            "I": 1,
            "V": 5,
            "X": 10,
            "L": 50,
            "C": 100,
            "D": 500,
            "M": 1000
        }

        val = 0
        n = len(s)
        for i in range(n):

            if (i+1 < n and roman[s[i]] < roman[s[i+1]]):
                val -= roman[s[i]]
            else:
                val += roman[s[i]]

        return val