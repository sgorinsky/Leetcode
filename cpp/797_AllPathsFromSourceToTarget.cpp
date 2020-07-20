class Solution {
public:
    vector<vector<int>> res;
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        vector<int> start;
        start.push_back(0);
        dfs(0, start, graph);
        return this->res;
    }
    void dfs(int idx, vector<int>& currList, vector<vector<int>>& graph) {
        for (int node : graph[idx]) {
            currList.push_back(node);
            dfs(node, currList, graph);
            currList.pop_back();
        }
        if (idx == graph.size()-1) {
            this->res.push_back(currList);
            return;
        }
    }
};
