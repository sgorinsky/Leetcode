class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int sold = -1000000, held = -1000000, reset = 0;
        for (int p : prices) {
            int pre = sold;
            sold = held + p;
            held = max(held, reset-p);
            reset = max(pre, reset);
        }
        return max(sold, reset);
    }
};
