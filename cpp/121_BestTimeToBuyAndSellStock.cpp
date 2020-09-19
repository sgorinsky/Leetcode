class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int profit = 0, small = 10000;
        for (int p : prices) {
            if (small < p)
                profit = max(p - small, profit);
            small = min(p, small);
        }
        return profit;
    }
};
