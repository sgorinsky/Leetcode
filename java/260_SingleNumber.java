class Solution {
    public int[] singleNumber(int[] nums) {
        int bitmask = 0;
        for (int n : nums) bitmask ^= n;
        
        int diff = bitmask & (-bitmask), x = 0;
        for (int n : nums) if ((diff & n) != 0) x ^= n;
        
        return new int[] {x, x^bitmask};
    }
}
