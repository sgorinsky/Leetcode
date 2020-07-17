class Solution:
    
    def solveSudoku(self, board: List[List[str]]) -> None:
        """
        Do not return anything, modify board in-place instead.
        """
        self.grid = board
        def isPossible(row, col, n):
            for i in range(9):
                curr = board[i][col]
                if curr == n:
                    return False

            for i in range(9):
                curr = board[row][i]
                if curr == n:
                    return False

            for i in range(9):
                curr = board[3*(row*3//9)+(i//3)][3*(col*3//9)+(i%3)]
                if curr == n:
                    return False
            return True
        
        def solve():
            for i in range(9):
                for j in range(9):
                    if board[i][j] == '.':
                        for n in range(1, 10):
                            if isPossible(i, j, str(n)):
                                board[i][j] = str(n)
                                if not solve(): board[i][j] = '.'
                        return False
            self.grid = [[entry for entry in row] for row in board] 
            return True
        solve()
        board[:] = self.grid[:]
