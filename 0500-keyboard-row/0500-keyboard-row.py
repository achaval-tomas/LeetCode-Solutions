class Solution(object):
    def findWords(self, words):
        row1 = "qwertyuiopQWERTYUIOP"
        row2 = "asdfghjklASDFGHJKL"
        row3 = "zxcvbnmZXCVBNM"
        ans = []
    
        for word in words:
            length = len(word)
            b = True
            if word[0] in row1:
                for i in range(length):
                    if word[i] not in row1:
                        b = False
                        break
            
            if word[0] in row2 and b:
                for i in range(length):
                    if word[i] not in row2:
                        b = False
                        break

            if word[0] in row3 and b:
                for i in range(length):
                    if word[i] not in row3:
                        b = False
                        break

            if b:
                ans.append(word)
        return ans