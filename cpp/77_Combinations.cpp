class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> results;
        vector<int> curr;
        helper(results, curr, 1, n, k);
        return results;
    }
    
    void helper(vector<vector<int>>& results, vector<int>& curr, int start, int n, int k) {
        if (curr.size() == k) {
            results.push_back(curr);
        } else {
            for (int i = start; i <= n; ++i) {
                curr.push_back(i);
                helper(results, curr, i + 1, n, k);
                curr.pop_back();
            }
        }
    }
};
