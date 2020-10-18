class Solution {
    int[][] directions = {
        new int[] {0, 1},
        new int[] {1, 0},
        new int[] {0, -1},
        new int[] {-1, 0}
    };
    char ISLAND = '1';
    public int numIslands(char[][] grid) {
        int count = 0;
        for (int i = 0; i < grid.length; ++i) {
            for (int j = 0; j < grid[0].length; ++j) {
                if (grid[i][j] == ISLAND) {
                    count++;
                    bfs(grid, i, j);
                }
            }
        }
        return count;
    }
    
    public void bfs(char[][] grid, int row, int col) {
        Queue<int[]> q = new LinkedList();
        q.add(new int[] { row, col });
        while (!q.isEmpty()) {
            int[] currIndices = q.poll();
            int i = currIndices[0];
            int j = currIndices[1];
            
            grid[i][j] = '2';
            for (int[] direction : directions) {
                int r = i + direction[0];
                int c = j + direction[1];
                if (canGoTo(grid, r, c)) {
                    grid[r][c] = '2';
                    q.add(new int[] { r, c });
                }
            }
        }
    }
    
    public boolean canGoTo(char[][] grid, int i, int j) {
        return i >= 0 && i < grid.length && j >= 0 && j < grid[0].length && grid[i][j] == '1';
    }
}
