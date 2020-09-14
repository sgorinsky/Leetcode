class Solution {
public:
    int rob(vector<int>& nums) {
        int prev_max = 0, curr_max = 0;
        
        for (int n : nums) {
            int temp = curr_max;
            curr_max = max(prev_max + n, curr_max);
            prev_max = temp;
        }
        return curr_max;
    }
};
