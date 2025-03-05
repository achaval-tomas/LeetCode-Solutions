class Solution(object):
    def spiralOrder(self, matrix):
        """
        :type matrix: List[List[int]]
        :rtype: List[int]
        """
        m = len(matrix)
        n = len(matrix[0])

        ans = [matrix[0][0]]
        matrix[0][0] = 200

        direction = "right"
        r, c = 0, 0
        while len(ans) < m*n:
            print(direction, ans)
            if direction == "right":
                r = max(0, min(r, m-1))
                c += 1
                if c >= n or matrix[r][c] == 200:
                    direction = "down"
                    c -= 1
                else:
                    ans.append(matrix[r][c])
                    matrix[r][c] = 200

            elif direction == "down":
                c = max(0, min(c, n-1))
                r += 1
                if r >= m or matrix[r][c] == 200:
                    direction = "left"
                    r -= 1
                else:
                    ans.append(matrix[r][c])
                    matrix[r][c] = 200

            elif direction == "left":
                r = max(0, min(r, m-1))
                c -= 1
                if c < 0 or matrix[r][c] == 200:
                    direction = "up"
                    c += 1
                else:
                    ans.append(matrix[r][c])
                    matrix[r][c] = 200
            
            elif direction == "up":
                c = max(0, min(c, n-1))
                r -= 1
                if r < 0 or matrix[r][c] == 200:
                    direction = "right"
                    r += 1
                else:
                    ans.append(matrix[r][c])
                    matrix[r][c] = 200

        return ans