class Solution {
public:
    int count = 0;
    int countArrangement(int n) {
        bool used[n + 1];
        memset(used, false, n + 1);
        return backtrack(n, 1, used);
    }
    
    int backtrack(int n, int idx, bool used[]) {
        if (idx > n) return ++count;
        for (int i = 1; i <= n; ++i) {
            if (!used[i] && (idx % i == 0 || i % idx == 0)) {
                used[i] = true;
                backtrack(n, idx + 1, used);
                used[i] = false;
            }
        }
        return count;
    }
};
