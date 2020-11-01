class Solution {
public:
    bool canFormArray(vector<int>& arr, vector<vector<int>>& pieces) {
        if (pieces.empty()) return arr.empty();
        else if (arr.empty()) return pieces.empty();
        
        unordered_map<int, int> orders;
        for (int i = 0; i < arr.size(); ++i)
            orders[arr[i]] = i;
        
        for (vector<int> row : pieces) {
            for (int i = 0; i < row.size() - 1; ++ i) {
                if (orders.find(row[i]) == orders.end() || orders[row[i+1]] - 1 != orders[row[i]]) return false;
            }
        }
        return true;
    }
};
