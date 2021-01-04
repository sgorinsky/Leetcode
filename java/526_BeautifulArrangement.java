class Solution {
    int count = 0;
    public int countArrangement(int n) {
        boolean[] visited = new boolean[n + 1];
        return backtrack(n, 1, visited);
    }
    
    public int backtrack(int n, int idx, boolean[] visited) {
        if (idx > n) return ++count;
        for (int i = 1; i <= n; ++i) {
            if (!visited[i] && (i % idx == 0 || idx % i == 0)) {
                visited[i] = true;
                backtrack(n, idx + 1, visited);
                visited[i] = false;
            }
        }
        return count;
    }
}
