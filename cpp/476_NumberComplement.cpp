class Solution {
public:
    int findComplement(int num) {
        int bitmask = num, i = 1;
        while (i < 32) {
            bitmask |= (bitmask >> i);
            i <<= 1;
        }
        return bitmask ^ num;
    }
};
