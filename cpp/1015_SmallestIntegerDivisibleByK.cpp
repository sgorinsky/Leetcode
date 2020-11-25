class Solution {
public:
    int smallestRepunitDivByK(int K) {
        if (K % 2 == 0 || K % 5 == 0) return -1;
        int length = 1;
        int n = 1;
        while (length < 10000000) {
            if (n % K == 0 || n == 0) return length;
            n = (n * 10 + 1) % K;
            length++;
        }
        return -1;
    }
};
