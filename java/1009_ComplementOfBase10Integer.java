class Solution {
    public int bitwiseComplement(int N) {
        if (N == 0) return 1;
        int temp = N, currentBit = 1;
        
        while (temp > 0) {
            temp >>= 1;
            N = N ^ currentBit;
            currentBit <<= 1;
        }
        return N;
    }
}
