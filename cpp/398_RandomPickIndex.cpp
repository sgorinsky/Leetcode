class Solution {
public:
    unordered_map<int, vector<int>> num_counts = {};
    Solution(vector<int>& nums) {
        for (int i = 0; i < nums.size(); ++i) {
            int num = nums[i];
            if (num_counts.find(num) == num_counts.end()) {
                num_counts[num]= vector<int>{i};
            } else {
                num_counts[num].push_back(i);
            }
        }
    }
    
    int pick(int target) {
        int r = rand() % num_counts[target].size();
        return num_counts[target][r];
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * int param_1 = obj->pick(target);
 */
