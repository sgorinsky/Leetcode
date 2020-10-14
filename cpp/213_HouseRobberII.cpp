class Solution {
public:
    int rob(vector<int>& nums) {
        int N = nums.size();
        if (N == 1) return nums[0];
        
        return max(robPath(nums, 0, N-2), robPath(nums, 1, N-1));
    }
    
    int robPath(vector<int>& nums, int start, int end) {
        int prev = 0, high = 0;
        for (int i = start; i <= end; ++i) {
            int temp = high;
            high = max(prev + nums[i], high);
            prev = temp;
        }
        return high;
    }
};
