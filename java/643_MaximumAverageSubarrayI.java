class Solution {
    public double findMaxAverage(int[] nums, int k) {
        int n = nums.length, trail = 0;
        double high = -10000, sum = 0, K = (double) k;
        for (int i = 0; i < n; ++i) {
            if (i < k) {
                sum += nums[i];
            } else {
                high = Math.max(high, sum / K);
                sum = sum + nums[i] - nums[trail++];
            }
        }
        return Math.max(high, sum / K);
    }
}
