class Solution {
public:
    double champagneTower(int poured, int query_row, int query_glass) {
        vector<vector<double>> dp(query_row + 1, vector<double>(query_row + 1, 0));
        dp[0][0] = poured;
        for (int i = 1; i <= query_row; ++i) {
            for (int j = 0; j <= query_row + 1; ++j) {
                if (j == 0) {
                    dp[i][j] = max(0, (dp[i-1][j] - 1) / 2.0);
                } else if (j == i) {
                    dp[i][j] = max(0, (dp[i-1][j-1] - 1) / 2.0);
                    break;
                } else {
                    dp[i][j] = max(0, (dp[i-1][j] - 1) / 2.0) + max(0, (dp[i-1][j-1] - 1) / 2.0);
                }
            }
        }
        return min(1.0, dp[query_row][query_glass]);
    }
    
    double max(double a, double b) {
        return a > b ? a : b;
    }
};
