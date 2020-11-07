class Solution {
public:
    int threshold;
    int smallestDivisor(vector<int>& nums, int t) {
        threshold = t;
        
        int left = 1, right = 2;
        int mid = (left + right) >> 1;
        while (compute_sum(nums, right) > threshold) {
            left = right;
            right <<= 1;
        }
        
        while (left <= right) {
            int mid = left + (right - left) / 2;
            long total = compute_sum(nums, mid);
            if (total <= threshold) right = mid - 1;
            else left = mid + 1;
        }
        return left;
    }
    
    int compute_sum(vector<int>& nums, int divisor) {
        int total = 0;
        for (int n : nums) {
            total += n / divisor + (n % divisor != 0 ? 1 : 0);
            if (total > threshold) break;
        }
        return total;
    }
};
