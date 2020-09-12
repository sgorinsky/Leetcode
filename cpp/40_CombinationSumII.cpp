class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end(), [](const int a, const int b) {
            return a < b;
        });
        
        vector<vector<int>> result;
        vector<int> curr;
        combine(curr, 0, 0, target, candidates, result);
        return result;
    }
    
    void combine(vector<int>& curr, int sum, int start, int target, vector<int>& candidates, vector<vector<int>>& result) {
        if (sum == target) {
            result.push_back(curr);
            return;
        } else if (sum > target) {
            return;
        }
        
        for (int i = start; i < candidates.size(); ++i) {
            int n = candidates[i];
            if (i != start && candidates[i] == candidates[i-1]) continue;
            
            curr.push_back(n);
            combine(curr, sum + n, i + 1, target, candidates, result);
            curr.pop_back();
        }
    }
};
