def convert(list):
    s = [str(i) for i in list]
    res = int("".join(s)) 
    return(res)


class Solution(object):
    def plusOne(self, digits):
        return list(map(int, str(convert(digits)+1)))
        