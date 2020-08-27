class Solution:
    directions = [(0, 1), (1, 0), (0, -1), (-1, 0)]
    
    def hasPath(self, maze: List[List[int]], start: List[int], destination: List[int]) -> bool:
        self.found = False
        self.visited = set()
        
        if not maze or not maze[0] or maze[destination[0]][destination[1]] == 1:
            return False
        
        n_rows, n_cols = len(maze), len(maze[0])
        def canGo(row, col):
            return n_rows > row >= 0 and n_cols > col >= 0 and maze[row][col] != 1
        
        def helper(row, col, direction):
            d_row, d_col = row + direction[0], col + direction[1]
            if row == destination[0] and col == destination[1]:
                if not canGo(d_row, d_col):
                    self.found = True
                    return True
            
            if (row, col) not in self.visited and not self.found:
                if canGo(d_row, d_col):
                    helper(d_row, d_col, direction)
                else:
                    self.visited.add((row, col))
                    for r_move, c_move in self.directions:
                        new_row, new_col = row + r_move, col + c_move
                        if canGo(new_row, new_col):
                            helper(new_row, new_col, (r_move, c_move))
            return self.found
        
        for direction in self.directions:
            if helper(start[0], start[1], direction):
                return True
            
        return False
                    
