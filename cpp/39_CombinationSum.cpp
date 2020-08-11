class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        unordered_map<int, vector<vector<int>>> d = {};
        
        for (int cand : candidates) {
            for (int i = 0; i <= target; ++i) {
                if (i == cand) {
                    if (d.find(i) == d.end()) {
                        d[i] = {{i}};
                    } else {
                        d[i].push_back({cand});
                    }
                } else if (i-cand > 0 && d.find(i-cand) != d.end()) {
                    for (vector<int> num_set : d[i-cand]) {
                        num_set.push_back(cand);
                        if (d.find(i) == d.end()) {
                            d[i] = {num_set};
                        } else {
                            d[i].push_back({num_set});
                        }
                    }
                }
            }
        }
        return d.find(target) != d.end() ? d[target] : vector<vector<int>>{};
    }
};
