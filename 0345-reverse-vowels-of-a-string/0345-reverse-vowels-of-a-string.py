class Solution(object):
    def reverseVowels(self, s):
        """
        :type s: str
        :rtype: str
        """
        x = list(s)
        vowels = "aeiouAEIOU"
        
        ind = []
        for i in range(len(x)):
            if x[i] in vowels:
                ind.append(i)

        for i in range(int(len(ind)/2)):
            x[ind[i]], x[ind[-i-1]] = x[ind[-i-1]], x[ind[i]]

        return ''.join(x)
        