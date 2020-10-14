class Solution {
    public int rob(int[] nums) {
        int N = nums.length;
        if (N == 1) return nums[0];
        return Math.max(robPath(nums, 0, N-2), robPath(nums, 1, N-1));
    }
    
    public int robPath(int[] nums, int start, int end) {
        int prevSum = 0, currSum = 0;
        for (int i = start; i <= end; ++i) {
            int temp = currSum;
            currSum = Math.max(prevSum + nums[i], currSum);
            prevSum = temp;
        }
        return currSum;
    }
}
