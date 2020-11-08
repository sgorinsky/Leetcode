class Solution {
public:
    int getMaximumGenerated(int n) {
        if (n == 0) return 0;
        
        vector<int> dp(n + 1, 0);
        dp[1] = 1;
        for (int i = 2; i <= n; ++i) {
            if (i % 2 == 0) {
                dp[i] = dp[i / 2];
            } else {
                dp[i] = dp[i / 2] + dp[i / 2 + 1];
            }
        }
        return maxOfArray(dp);
        
    }
    
    int maxOfArray(vector<int>& arr) {
        int high = 0;
        for (int i = 0; i < arr.size(); ++i) {
            high = max(arr[i], high);
        }
        return high;
    }

};
