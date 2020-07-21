class Solution {
    char[][] board;
    boolean[][] visited;
    boolean isPossible = false;
    public boolean exist(char[][] board, String word) {
        this.board = board;
        this.visited = new boolean[board.length][board[0].length];
        for (int i = 0; i < this.visited.length; ++i) {
            for (int j = 0; j < this.visited[0].length; ++j) {
                this.visited[i][j] = false;
            }
        }
        for (int i = 0; i < this.visited.length; ++i) {
            for (int j = 0; j < this.visited[0].length; ++j) {
                check(i, j, 0, word);
                if (this.isPossible) return true;
            }
        }
        return false;
        
    }
    
    public boolean check(int i, int j, int idx, String word) {
        if (this.visited[i][j] || word.charAt(idx) != this.board[i][j]) {
            return false;
        } else if (idx == word.length()-1 && word.charAt(idx) == this.board[i][j]) {
            this.isPossible = true;
            return true;
        }
        
        if (!this.visited[i][j] && !this.isPossible) {
            this.visited[i][j] = true;
            if (i > 0 && word.charAt(idx+1) == this.board[i-1][j]) {
                check(i-1, j, idx+1, word);
            }
            if (j > 0 && word.charAt(idx+1) == this.board[i][j-1]) {
                check(i, j-1, idx+1, word);
            }
            if (i < this.board.length-1 && word.charAt(idx+1) == this.board[i+1][j]) {
                check(i+1, j, idx+1, word);
            }
            if (j < this.board[0].length-1 && word.charAt(idx+1) == this.board[i][j+1]) {
                check(i, j+1, idx+1, word);
            }
            this.visited[i][j] = false;
        }
        return this.isPossible;
    }
}
