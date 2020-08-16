class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int N = prices.size();
        if (N <= 1)
            return 0;
        
        int leftMin = prices[0];
        int rightMax = prices[N-1];
        
        vector<int> leftProfits(N, 0);
        vector<int> rightProfits(N+1, 0);
        
        for (int i = 1; i < N; ++i) {
            leftProfits[i] = max(leftProfits[i-1], prices[i] - leftMin);
            leftMin = min(leftMin, prices[i]);
            
            int r = N - i - 1;
            rightProfits[r] = max(rightProfits[r+1], rightMax - prices[r]);
            rightMax = max(rightMax, prices[r]);
        }
        
        int maxProfit = 0;
        for (int i = 0; i < N; ++i)
            maxProfit = max(maxProfit, leftProfits[i] + rightProfits[i+1]);
        
        return maxProfit;
    }
};
