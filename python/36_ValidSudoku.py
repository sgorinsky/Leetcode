class Solution:
    def isValidSudoku(self, board: List[List[str]]) -> bool:
        for i in range(9): # sudoku board is 9x9
            
            # row
            row_set = self.create_set(1,9)
            for j in range(9):
                if board[i][j] in row_set: 
                    if board[i][j] != '.': row_set.remove(board[i][j])
                else: return False
            
            # col
            col_set = self.create_set(1,9)
            for j in range(9):
                if board[j][i] in col_set: 
                    if board[j][i] != '.': col_set.remove(board[j][i])
                else: return False
            
            # 3x3 square
            square_set, start = self.create_set(1,9), i*3
            for j in range(9):
                current = board[(3*(start//9))+(j//3)][(start%9)+(j%3)]
                if current in square_set:
                    if current != '.': square_set.remove(current)
                else: return False
        return True
            
            
                
    def create_set(self, start, end):
        res = set()
        res.add(".")
        for n in range(start, end+1): res.add(str(n))
        return res
