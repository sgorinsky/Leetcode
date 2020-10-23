class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        int small = INT_MAX;
        for (int j = 0; j < nums.size(); ++j) {
            small = min(small, nums[j]);
            for (int k = j + 1; k < nums.size(); ++k) {
                if (small < nums[k] && nums[k] < nums[j]) return true;
            }
        }
        return false;
    }
};
