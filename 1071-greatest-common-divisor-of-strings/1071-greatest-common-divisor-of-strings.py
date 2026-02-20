class Solution(object):
    def gcdOfStrings(self, str1, str2):
        """
        :type str1: str
        :type str2: str
        :rtype: str
        """
        def divides(t, s):
            if len(t) == 0:
                return True

            x = t
            while len(x) < len(s):
                x += t

            return x == s

        x = str1
        while not (divides(x, str1) and divides(x, str2)):
            x = x[:len(x)-1]

        return x
        