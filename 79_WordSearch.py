class Solution:
    def exist(self, board: List[List[str]], word: str) -> bool:
        if not board or not board[0] or not word:
            return False
        if len(word) > len(board)*len(board[0]):
            return False
        
        m, n = len(board), len(board[0])
        self.wl = [x for x in word]
        self.visited = [[False for _ in range(n)] for _ in range(m)]
        
        for i in range(m):
            for j in range(n):
                if self.helper(i, j, board, 0):
                    return True
        return False
    
    def helper(self, i, j, matrix, idx):
        m, n = len(self.visited), len(self.visited[0])
        if idx == len(self.wl):
            return True
        elif idx == len(self.wl)-1:
            return matrix[i][j] == self.wl[idx]
        else:
            if matrix[i][j] == self.wl[idx]:
                self.visited[i][j] = True
				
                # Search along four directioins
                if i+1 < m and not self.visited[i+1][j]:
                    if self.helper(i+1, j, matrix, idx+1):
                        return True
                if i-1 >= 0 and not self.visited[i-1][j]:
                    if self.helper(i-1, j, matrix, idx+1):
                        return True
                if j+1 < n and not self.visited[i][j+1]:
                    if self.helper(i, j+1, matrix, idx+1):
                        return True
                if j-1 >= 0 and not self.visited[i][j-1]:
                    if self.helper(i, j-1, matrix, idx+1):
                        return True
						
				#i, j is not a valid starting point
                self.visited[i][j] = False                
            else:
                return False
