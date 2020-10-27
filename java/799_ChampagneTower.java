class Solution {
    public double champagneTower(int poured, int query_row, int query_glass) {
        double[][] dp = new double[query_row + 1][query_row + 1];
        dp[0][0] = poured;
        for (int i = 1; i <= query_row; ++i) {
            for (int j = 0; j <= query_row; ++j) {
                if (j == 0) dp[i][j] = Math.max(0, (dp[i-1][j] - 1) / 2.0);
                else if (j < i) dp[i][j] = Math.max(0, (dp[i-1][j-1] - 1) / 2.0) + Math.max(0, (dp[i-1][j] - 1) / 2.0);
                else {
                    dp[i][j] = Math.max(0, (dp[i-1][j-1] - 1) / 2.0);
                    break;
                }
            }
        }
        return Math.min(1.0, dp[query_row][query_glass]);
    }
}
