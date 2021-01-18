class Solution {
public:
    int countVowelStrings(int n) {
        return countPermutations(n, 0, 0);
    }
    
    int countPermutations(int n, int start, int k) {
        if (k == n)  return 1;
        
        int count = 0;
        for (int i = start; i < 5; ++i)
            count += countPermutations(n, i, k + 1);
        
        return count;
    }
};

class Solution {
public:
    int countVowelStrings(int n) {
        vector<vector<int>> dp;
        for (int i = 0; i <= n; ++i) dp.push_back({1, 1, 1, 1, 1});
        
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j < 5; ++j) {
                dp[i][j] = dp[i][j-1] + dp[i-1][j];
            }
        }
        return dp[n][4];
    }
};
