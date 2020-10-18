class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        if (prices.size() <= 1) return 0;
        
        int N = prices.size();
        if (k >= N) {
            int profit = 0;
            for (int i = 1; i < N; ++i) profit += max(0, prices[i] - prices[i-1]);
            return profit;
        }

        vector<vector<int>> dp;
        for (int i = 0; i <= k; ++i)
            dp.push_back(vector<int>(N, 0));
        
        for (int i = 1; i <= k; ++i) {
            int max_profit = -prices[0];
            for (int j = 1; j < N; ++j) {
                dp[i][j] = max(dp[i][j-1], prices[j] + max_profit);
                max_profit = max(max_profit, -prices[j] + dp[i-1][j]);
            }
        }
        return dp[k][N-1];
    }
};
