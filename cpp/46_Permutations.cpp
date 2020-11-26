class Solution {
public:
    vector<vector<int>> results;
    vector<vector<int>> permute(vector<int>& nums) {
        vector<int> curr;
        unordered_set<int> nums_set;
        for (int n : nums) nums_set.insert(n);
        helper(nums, nums_set, curr);
        return results;
    }
    
    void helper(vector<int>& nums, unordered_set<int>& nums_set, vector<int>& curr) {
        if (nums_set.empty()) {
            results.push_back(vector<int>(curr));
            return;
        }
        
        for (int n : nums) {
            if (nums_set.find(n) != nums_set.end()) {
                nums_set.erase(n);
                curr.push_back(n);
                helper(nums, nums_set, curr);
                nums_set.insert(n);
                curr.pop_back();
            }
        }
    }
};
