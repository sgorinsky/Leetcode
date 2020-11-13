class Solution {
public:
    vector<vector<int>> res;
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<int> curr;
        sort(nums.begin(), nums.end());
        return backtrack(nums, curr);
    }
    
    vector<vector<int>> backtrack(vector<int>& nums, vector<int>& curr) {
        if (nums.size() == curr.size()) {
            res.push_back(curr);
            return res;
        }
        
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] == -11 || (i > 0 && nums[i] == nums[i-1])) continue;
            int temp = nums[i];
            nums[i] = -11;
            curr.push_back(temp);
            backtrack(nums, curr);
            curr.pop_back();
            nums[i] = temp;
        }
        
        return res;
    }
};
