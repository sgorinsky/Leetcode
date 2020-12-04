class Solution {
public:
    double high = -100000;
    double findMaxAverage(vector<int>& nums, int k) {
        int N = nums.size();
        vector<vector<int>> dp(N, vector<int>(N, 0));
        
        int sum = 0;
        for (int n : nums) sum += n;
        
        dp[0][N-1] = sum;
        return pascal(dp, nums, 0, N - 1, k);
    }
    
    double pascal(vector<vector<int>>& dp, vector<int>& nums, int i, int j, int k) {
        if (j - i + 1 < k || i > j) return 0;
        
        double curr_avg = ((double) dp[i][j]) / (j - i + 1);
        high = curr_avg > high ? curr_avg : high;
        
        dp[i+1][j] = dp[i][j] - nums[i];
        dp[i][j-1] = dp[i][j] - nums[j];
        
        if (i < nums.size() && dp[i+1][j] != 0) pascal(dp, nums, i + 1, j, k);
        if (j >= 0 && dp[i][j-1] != 0) pascal(dp, nums, i, j - 1, k);
        
        return high;
    }
};
