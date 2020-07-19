class Solution {
    public int arrangeCoins(int n) {
        long left = 0, right = n;
        long k, curr;
        while (left <= right) {
            k = left + (right - left) / 2;
            curr = k * (k + 1) / 2;
            
            if (curr == n) return (int)k;
            if (n < curr) {
                right = k - 1;
            } else {
                left = k + 1;
            }
        }
        return (int) right;
    }
}

class Solution {
    public int arrangeCoins(int n) {
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
}
