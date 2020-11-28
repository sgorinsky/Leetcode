class Solution {
    HashMap<Integer, Boolean> memo = new HashMap<Integer, Boolean>();
    public boolean canPartition(int[] nums) {
        int N = nums.length;
        int sum = 0;
        for (int n : nums) sum += n;
        return sum % 2 == 0 & helper(nums, N - 1, sum / 2);
    }
    
    public boolean helper(int[] nums, int idx, int currentTargetSum) {
        if (memo.containsKey(currentTargetSum)) return memo.get(currentTargetSum);
        else if (currentTargetSum == 0) return true;
        else if (idx == 0 || currentTargetSum < 0) return false;
        
        memo.put(currentTargetSum, helper(nums, idx - 1, currentTargetSum - nums[idx]) || helper(nums, idx - 1, currentTargetSum));
        return memo.get(currentTargetSum);
    }
}
