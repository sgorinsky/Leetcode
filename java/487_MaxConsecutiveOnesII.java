class Solution {
    public int findMaxConsecutiveOnes(int[] nums) {
        int left = 0, lastZero = -1, high = 0;
        for (int i = 0; i < nums.length; ++i){
            if (nums[i] == 0) {
                if (lastZero >= 0)
                    left = lastZero + 1; // next possible, note how we declare this for last 0
                lastZero = i;
            }
            high = high < i - left + 1 ? i - left + 1 : high;
        }
        return high;
    }
}
