class Solution {
public:
    int minJumps(vector<int>& arr) {
        unordered_map<int, vector<int>> graph;
        for (int i = 0; i < arr.size(); ++i) {
            if (graph.find(arr[i]) != graph.end()) {
                graph[arr[i]].push_back(i);
            } else {
                graph[arr[i]] = {i};
            }
        }
        
        vector<int> nodes = {0};
        vector<bool> visited(arr.size(), false);
        int count = 0;
        
        while (!nodes.empty()) {
            vector<int> nxt_nodes;
            for (int node : nodes) {
                if (node == arr.size() - 1){
                    return count;
                }
                
                for (int neighbor : graph[arr[node]]) {
                    if (!visited[neighbor]) {
                        nxt_nodes.push_back(neighbor);
                        visited[neighbor] = true;
                    }
                }
                
                for (int neighbor : {node - 1, node + 1}) {
                    if (neighbor >= 0 && neighbor < arr.size() && !visited[neighbor]) {
                        nxt_nodes.push_back(neighbor);
                        visited[neighbor] = true;
                    }
                }
                
                graph[arr[node]] = {};
            }
            
            nodes = nxt_nodes;
            count++;
        }
        
        return -1;
    }
};
