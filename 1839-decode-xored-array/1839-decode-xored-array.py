class Solution(object):
    def decode(self, encoded, first):
        arr = []
        arrlen = len(encoded)+1
        arr.append(first)
        for i in range(1, arrlen):
            arr.append(arr[i-1] ^ encoded[i-1])
        return arr 
