class Solution {
    private ArrayList<Integer>[] adjacencies;
    private int highest = 0;
    public int numOfMinutes(int n, int headID, int[] manager, int[] informTime) {
        this.adjacencies = new ArrayList[n];
        for (int i = 0; i < n; ++i) {
            this.adjacencies[i] = new ArrayList<Integer>();
        }
        for (int i = 0; i < n; ++i) {
            if (manager[i] != -1) this.adjacencies[manager[i]].add(i);
        }
        dfs(headID, informTime[headID], informTime);
        return this.highest;
    }

    public int dfs(int idx, int currTotal, int[] informTime) {
        if (this.adjacencies[idx].isEmpty()) {
            if (currTotal > this.highest) {
                this.highest = currTotal;
            }
            return this.highest;
        }
        for (int p : this.adjacencies[idx]) {
            dfs(p, currTotal+informTime[p], informTime);
        }
        return this.highest;
    }
}
// or this solution
// same solution except adjacency list is ArrayList of ArrayLists instead of array of ArrayLists
class Solution {
    private List<List<Integer>> adjacencies = new ArrayList<List<Integer>>();
    private int highest = 0;
    public int numOfMinutes(int n, int headID, int[] manager, int[] informTime) {
        for (int i = 0; i < n; ++i) {
            this.adjacencies.add(new ArrayList<Integer>());
        }
        for (int i = 0; i < n; ++i) {
            if (manager[i] != -1) this.adjacencies.get(manager[i]).add(i);
        }
        dfs(headID, informTime[headID], informTime);
        return this.highest;
    }

    public int dfs(int idx, int currTotal, int[] informTime) {
        if (this.adjacencies.get(idx).isEmpty()) {
            if (currTotal > this.highest) {
                this.highest = currTotal;
            }
            return this.highest;
        }
        for (int p : this.adjacencies.get(idx)) {
            dfs(p, currTotal+informTime[p], informTime);
        }
        return this.highest;
    }
}
