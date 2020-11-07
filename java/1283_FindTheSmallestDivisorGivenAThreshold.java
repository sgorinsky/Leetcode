class Solution {
    int t;
    public int smallestDivisor(int[] nums, int threshold) {
        t = threshold;
        int left = 1, right = 2;
        while (computeSum(nums, right) > threshold) {
            left = right;
            right <<= 1;
        }
        
        while (left <= right) {
            int mid = left + (right - left) / 2;
            int total = computeSum(nums, mid);
            if (total > threshold) left = mid + 1;
            else right = mid - 1;
        }
        return left;
    }
    
    public int computeSum(int[] nums, int divisor) {
        int total = 0;
        for (int n : nums) {
            total += n / divisor + (n % divisor == 0 ? 0 : 1);
            if (total > t) break;
        }
        return total;
    }
}
