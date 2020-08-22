class Solution {
    public void moveZeroes(int[] nums) {
        int nonZero = 1;
        for (int i = 0; i < nums.length; ++i) {
            if (nums[i] == 0) {
                while (nonZero < nums.length && nums[nonZero] == 0) ++nonZero;
                if (nonZero < nums.length && nums[nonZero] != 0) {
                    nums[i] = nums[nonZero];
                    nums[nonZero++] = 0;
                }
            } else {
                ++nonZero;
            }
        }
    }
}
