class Solution {
public:
    int min_height = INT_MAX;
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        vector<unordered_set<int>> adjacencies;
        for (int i = 0; i < n; ++i) 
            adjacencies.push_back(unordered_set<int>());
        
        for (vector<int> edge : edges) {
            adjacencies[edge[0]].insert(edge[1]);
            adjacencies[edge[1]].insert(edge[0]);
        }
        
        unordered_map<int, int> node_depths;
        for (int i = 0; i < n; ++i) {
            node_depths[i] = INT_MAX;
            node_depths[i] = dfs(adjacencies, i, 1);
            min_height = min(min_height, node_depths[i]);
        }
        
        vector<int> min_height_trees;
        for (int i = 0; i < n; ++i) {
            if (node_depths[i] == min_height)
                min_height_trees.push_back(i);
        }
        return min_height_trees;
    }
    
    int dfs(vector<unordered_set<int>>& adjacencies, int node, int height) {
        if (adjacencies[node].empty() || height > min_height) return height;
        
        int depth = INT_MIN;
        for (int nei : adjacencies[node]) {
            adjacencies[nei].erase(node);
            depth = max(depth, dfs(adjacencies, nei, height + 1));
            adjacencies[nei].insert(node);
            if (depth > min_height) break;
        }
        return depth;
    }
};
