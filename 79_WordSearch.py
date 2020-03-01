class Solution:
    def exist(self, board: List[List[str]], word: str) -> bool:
        if not board or not board[0]: return False
        
        row_length, col_length = len(board), len(board[0])
        self.visited = [[False for _ in range(col_length)] for _ in range(row_length)]
        
        for i in range(row_length):
            for j in range(col_length):
                if self.check(i, j, word, board): return True
        
        return False
    
    def check(self, row, col, word, board):
        if not word: return True
        elif len(word) == 1: return word[0] == board[row][col]
        else:
            if board[row][col] == word[0]:
                self.visited[row][col] = True
                if row > 0 and not self.visited[row-1][col]:
                    if self.check(row-1, col, word[1:], board): return True

                if col > 0 and not self.visited[row][col-1]:
                    if self.check(row, col-1, word[1:], board): return True

                if row < len(board)-1 and not self.visited[row+1][col]:
                    if self.check(row+1, col, word[1:], board): return True

                if col < len(board[0])-1 and not self.visited[row][col+1]:
                    if self.check(row, col+1, word[1:], board): return True
                self.visited[row][col] = False
                
            else: 
                self.visited[row][col] = False
                return False
            
        
