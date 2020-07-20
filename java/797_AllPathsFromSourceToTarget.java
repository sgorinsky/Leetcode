class Solution {
    List<List<Integer>> res = new ArrayList<List<Integer>>();
    public List<List<Integer>> allPathsSourceTarget(int[][] graph) {
        List<Integer> start = new ArrayList<Integer>();
        start.add(0);
        dfs(0, start, graph);
        return this.res;
    }
    public void dfs(int idx, List<Integer> currList, int[][] graph) {
        int[] nodes = graph[idx];
        for (int i = 0; i < nodes.length; ++i) {
            currList.add(nodes[i]);
            dfs(nodes[i], currList, graph);
            currList.remove(currList.size()-1);
        }
        if (idx == graph.length-1) {
            this.res.add(new ArrayList<Integer>(currList));
            return;
        }
    }
}
