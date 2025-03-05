class Solution(object):
    def isValidSudoku(self, board):
        """
        :type board: List[List[str]]
        :rtype: bool
        """
        for r in board:
            seen = []
            for c in r:
                if c != "." and c in seen:
                    return False
                seen.append(c)
        
        for c in range(9):
            seen = []
            for r in range(9):
                if board[r][c] != "." and board[r][c] in seen:
                    return False
                seen.append(board[r][c])
        
        for v in range(0, 7, 3):
            for s in range(0, 7, 3):
                seen = []
                for r in range(v, v + 3):
                    for c in range(s, s + 3):
                        if board[r][c] != "." and board[r][c] in seen:
                            return False
                        seen.append(board[r][c])
        return True
