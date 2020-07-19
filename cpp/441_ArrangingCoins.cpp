class Solution {
public:
    int arrangeCoins(int n) {
        if (n < 0) {
            return -1;
        }
        int i = 0;
        int k = 1;
        int count = 0;
        
        while (n > 0) {
            if (k <= n) {
                ++count;
            }
            n -= k;
            ++k;
        }
        return count;
    }
};
