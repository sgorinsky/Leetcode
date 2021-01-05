class Solution {
public:
    int climbStairs(int n) {
        int stairs[n + 1];
        for (int i = 0; i < n + 1; ++i) {
            if (i > 1) stairs[i] = stairs[i - 1] + stairs[i - 2];
            else stairs[i] = 1;
        }
        return stairs[n];
    }
};
class Solution {
public:
    unordered_map<int, int> memo;
    int climbStairs(int n) {
        if (n <= 1) return 1;
        else if (memo.find(n) != memo.end()) return memo[n];
        
        memo[n] = climbStairs(n-1) + climbStairs(n-2);
        return memo[n];
    }
};
