class Solution {
public:
    bool canReach(vector<int>& arr, int start) {
        unordered_set<int> seen_idxs;
        return dfs(arr, seen_idxs, start);
    }
    
    bool dfs(vector<int>& arr, unordered_set<int>& seen_idxs, int idx) {
        if (idx < 0 || idx >= arr.size() || seen_idxs.find(idx) != seen_idxs.end()) {
            return false;
        } else if (arr[idx] == 0) {
            return true;
        } 
        
        seen_idxs.insert(idx);
        return dfs(arr, seen_idxs, idx - arr[idx]) || dfs(arr, seen_idxs, idx + arr[idx]);
    }
};
