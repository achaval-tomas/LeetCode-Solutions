class Solution(object):
    def checkString(self, s):
        bcount = 0
        for letters in s:
            if letters == 'b':
                bcount += 1
            elif letters == 'a' and bcount > 0:
                return False
        return True
        