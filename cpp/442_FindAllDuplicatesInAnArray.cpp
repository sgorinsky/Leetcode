class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        unordered_set<int> num_set = {};
        vector<int> res = {};
        for (int n : nums) {
            if (num_set.find(n) != num_set.end()) {
                res.push_back(n);
            } else {
                num_set.insert(n);
            }
        }
        return res;
    }
};
