class Solution:
    def solveSudoku(self, board: List[List[str]]) -> None:
        """
        Do not return anything, modify board in-place instead.
        """
        def valid_candidate(cand, row, col):
            for i in range(9):
                if row != i and board[i][col] == cand: return False
                if col != i and board[row][i] == cand: return False
                
                box_row = row // 3 * 3 + i // 3
                box_col = col // 3 * 3 + i % 3
                if (row != box_row and col != box_col) and board[box_row][box_col] == cand: return False
            return True
        
        def solve():
            for i in range(9):
                for j in range(9):
                    if board[i][j] == '.':
                        for n in range(1, 10):
                            if valid_candidate(str(n), i, j):
                                board[i][j] = str(n)
                                if solve(): return True
                                board[i][j] = '.'
                        return False
            return True
        
        solve()
