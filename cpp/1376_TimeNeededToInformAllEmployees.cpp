class Solution {
public:
    vector<vector<int>> adjacencies;
    int highest = 0;
    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {
        for (int i = 0; i < n; ++i) {
            this->adjacencies.push_back({}); // initializing adjacency vector with n empty lists
        }
        for (int i = 0; i < n; ++i) {
            if (manager[i] != -1) this->adjacencies[manager[i]].push_back(i);
        }
        return dfs(headID, informTime[headID], informTime);
    }
    int dfs(int idx, int currTotal, vector<int>& informTime) {
        if (this->adjacencies[idx].size() == 0) {
            if (currTotal > this->highest) {
                this->highest = currTotal;
            }
            return this->highest;
        }
        for (int p : this->adjacencies[idx]) {
            dfs(p, currTotal+informTime[p], informTime);
        }
        return this->highest;
    }
};
