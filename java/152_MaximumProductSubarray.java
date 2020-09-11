class Solution {
    public int maxProduct(int[] nums) {
        int N = nums.length;
        if (N == 0) return 0;
        
        int max = nums[0], min = nums[0];
        int high = max;
        
        for (int i = 1; i < N; ++i) {
            int curr = nums[i];
            int temp = Math.max(curr, Math.max(max * curr, min * curr));
            min = Math.min(curr, Math.min(curr * max, curr * min));
            
            max = temp;
            high = Math.max(max, high);
        }
        return high;
    }
}
