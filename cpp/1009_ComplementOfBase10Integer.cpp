class Solution {
public:
    int bitwiseComplement(int N) {
        if (N == 0)
            return 1;
        
        int temp = N, bit_mask = 0;
        while (temp > 0) {
            bit_mask = (bit_mask << 1) + 1;
            temp >>= 1;
        }
        return N ^ bit_mask;
    }
};
