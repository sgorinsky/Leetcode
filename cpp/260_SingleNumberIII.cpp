class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        vector<int> res = {};
        unordered_map<int, int> num_counts;
        
        for (int n : nums) {
            num_counts[n] = num_counts.find(n) == num_counts.end() ? 1 : 2;
        }
        
        for (int n : nums) {
            if (num_counts[n] == 1) res.push_back(n);
        }
        return res;
    }
};
