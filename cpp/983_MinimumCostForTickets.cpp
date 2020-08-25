class Solution {
public:
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        int last = days[days.size()-1];
        vector<int> dp(last+1, 0);
        unordered_set<int> all_days;
        
        for (int d : days)
            all_days.insert(d);
        
        for (int i = 1; i < last+1; ++i) {
            if (all_days.find(i) == all_days.end()) {
                dp[i] = dp[i-1];
            } else {
                int one = dp[i-1] + costs[0];
                int seven = dp[max(0, i-7)] + costs[1];
                int thirty = dp[max(0, i-30)] + costs[2];
                dp[i] = min(one, seven, thirty);
            }
        }
        return dp[dp.size()-1];
    }
    
    int min(const int& a, const int& b, const int& c) {
        return a <= b  && a <= c ? a : b < c ? b : c;
    }
};
