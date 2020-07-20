class Solution {
    private List<List<Integer>> res = new ArrayList<List<Integer>>();
    public List<List<Integer>> allPathsSourceTarget(int[][] graph) {
        List<Integer> start = new ArrayList<Integer>();
        start.add(0);
        dfs(0, start, graph);
        return this.res;
    }
    public void dfs(int idx, List<Integer> currList, int[][] graph) {
        for (int node : graph[idx]) {
            currList.add(node);
            dfs(node, currList, graph);
            currList.remove(currList.size()-1);
        }
        if (idx == graph.length-1) {
            this.res.add(new ArrayList<Integer>(currList));
            return;
        }
    }
}
