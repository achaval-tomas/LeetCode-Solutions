class Solution(object):
    def convert(self, s, numRows):
        """
        :type s: str
        :type numRows: int
        :rtype: str
        """
        substrs = ["" for _ in range(numRows)]
        direction = 1
        row = 0
        for i in range(len(s)):
                   
            substrs[row] += s[i]
            
            row += direction
            if row == -1 or row == numRows:
                direction *= -1
                row = max(0, min(row + 2*direction, numRows-1))

        ans = ""
        for s in substrs:
            ans += s

        return ans