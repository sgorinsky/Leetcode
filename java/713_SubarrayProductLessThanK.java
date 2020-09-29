class Solution {
    public int numSubarrayProductLessThanK(int[] nums, int k) {
        int product = 1, trail = 0, count = 0;
        for (int i = 0; i < nums.length; ++i) {
            product *= nums[i];
            while (product >= k && trail <= i)
                product /= nums[trail++];
            count += (i - trail + 1);
        }
        return count;
    }
}
