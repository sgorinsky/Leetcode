class Solution {
    public int findComplement(int num) {
        int bitmaskLength = (int) (Math.log(num) / Math.log(2.0)) + 1;
        int mask = (1 << bitmaskLength) - 1;
        return num ^ mask;
    }
}
