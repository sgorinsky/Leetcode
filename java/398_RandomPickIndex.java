class Solution {
    int[] nums;
    public Solution(int[] nums) {
        this.nums = nums;
    }
    
    public int pick(int target) {
        int r;
        do {
            r = (int)(Math.random() * nums.length);
        } while (nums[r] != target);
        
        return r;
            
    }
}
