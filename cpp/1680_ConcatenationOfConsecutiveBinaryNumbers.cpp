class Solution {
public:
    int mod = 1000000007;
    int concatenatedBinary(int n) {
        long x = 0;
        int shift = 0;
        for (int i = 1; i <= n; ++i) {
            if ((i & (i - 1)) == 0) shift++;
            x = ((x << shift) | i) % mod;
        }
        return x;
    }
};

class Solution {
public:
    int mod = 1000000007;
    int concatenatedBinary(int n) {
        long x = 0;
        int shift = 0, val = 1;
        for (int i = 1; i <= n; ++i) {
            if (i == val) {
                val *= 2;
                shift++;
            }
            x = ((x << shift) | i) % mod;
        }
        return x;
    }
};

class Solution {
public:
    int concatenatedBinary(int n) {
        const int MOD = 1000000007;
        int length = 0;   // bit length of addends
        long result = 0;  // long accumulator
        for (int i = 1; i <= n; i++) {
            // when meets power of 2, increase the bit length
            if ((i & (i - 1)) == 0) {
                length++;
            }
            result = ((result << length) | i) % MOD;
        }
        return result;
    }
};
