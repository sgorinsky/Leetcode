class Solution {
    private static final List<int[]> DIRECTIONS = Arrays.asList(
        new int[] { 1,  0},
        new int[] {-1,  0},
        new int[] { 0,  1},
        new int[] { 0, -1}
    );
    private static final int GATE = 0;

    public void wallsAndGates(int[][] rooms) {
        int m = rooms.length;
        if (m == 0) return;
        int n = rooms[0].length;
        Queue<int[]> q = new LinkedList<>();
        for (int row = 0; row < m; row++) {
            for (int col = 0; col < n; col++) {
                if (rooms[row][col] == GATE) {
                    q.add(new int[] { row, col });
                }
            }
        }
        while (!q.isEmpty()) {
            int[] point = q.poll();
            int i = point[0];
            int j = point[1];
            
            for (int[] direction : DIRECTIONS) {
                int r = i + direction[0];
                int c = j + direction[1];
                if (canGo(r, c, i, j, rooms)) {
                    rooms[r][c] = rooms[i][j] + 1;
                    q.add(new int[] { r, c });
                }
            }
        }
    }
    
    public boolean canGo(int r, int c, int i, int j, int[][] rooms) {
        return r >= 0 && r < rooms.length && c >= 0 && c < rooms[0].length && rooms[r][c] > 0 && rooms[r][c] > rooms[i][j];
    }
}
