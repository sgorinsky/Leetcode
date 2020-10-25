class Solution {
public:
    bool winnerSquareGame(int n) {
        vector<bool> dp = {false};
        vector<int> squares = {1};
        for (int i = 1; i <= n; ++i)  {
            if (sqrt(i) == (int) sqrt(i)) {
                squares.push_back(i);
                dp.push_back(true);
            } else {
                for (int sq : squares) {
                    if (dp[i-sq] == false) {
                        dp.push_back(true);
                        break;
                    }
                }
                if (dp.size() == i) dp.push_back(false);
            }
        }
        return dp[n];
    }
};
