class Solution {
public:
    int getMaximumGenerated(int n) {
        if (n <= 1) 
            return n;
        
        int dp[n + 1];
        memset(dp, 0, n + 1);
        dp[1] = 1;
        
        int high = 0;
        for (int i = 2; i < n + 1; ++i) {
            dp[i] = i % 2 == 0 ? dp[i / 2] : dp[i / 2] + dp[i / 2 + 1];
            high = max(high, dp[i]);
        }
        return high;
    }
};

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
