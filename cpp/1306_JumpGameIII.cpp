class Solution {
public:
    bool canReach(vector<int>& arr, int start) {
        return dfs(arr, start);
    }

    bool dfs(vector<int>& arr, int idx) {
        if (idx < 0 || idx >= arr.size() || arr[idx] < 0) {
            return false;
        } else if (arr[idx] == 0) {
            return true;
        }

        arr[idx] = -arr[idx];
        return dfs(arr, idx - arr[idx]) || dfs(arr, idx + arr[idx]);
    }
};
