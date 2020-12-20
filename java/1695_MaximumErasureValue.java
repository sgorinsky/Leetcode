class Solution {
    public int maximumUniqueSubarray(int[] nums) {
        int l = 0, high = 0, sum = 0;
        int[] counts = new int[10001], lasts = new int[10001];
        for (int i = 0; i < nums.length; ++i) {
            int n = nums[i];
            sum += n;
            if (counts[n] > 0) {
                for (int j = l; j <= lasts[n]; ++j) {
                    sum -= nums[j];
                    counts[nums[j]] -= 1;
                }
                l = lasts[n] + 1;
            }
            lasts[n] = i;
            counts[n] = 1;
            high = Math.max(high, sum);
        }
        return high;
    }
}
