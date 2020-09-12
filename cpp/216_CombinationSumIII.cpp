class Solution {
public:
    int top = 9;
    vector<vector<int>> combinationSum3(int k, int n) {
        if (k == 0) 
            return {{}};
        
        top = min(n, top);
        vector<vector<int>> result;
        combine({}, 0, k, n, result);
        return result;
    }
    
    void combine(vector<int> curr, int sum, int k, int n, vector<vector<int>>& result) {
        if (sum == n && curr.size() == k) {
            result.push_back(curr);
            return;
        } else if (curr.size() > k || sum > n) {
            return;
        } 
        
        for (int num = curr.empty() ? 1 : curr.back() + 1; num <= top; ++num) {
            curr.push_back(num);
            combine(curr, sum + num, k, n, result);
            curr.pop_back();
        }
    }
};
