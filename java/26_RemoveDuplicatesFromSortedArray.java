class Solution {
    public int removeDuplicates(int[] nums) {
        int left = 1, right = 1;
        
        while (right < nums.length) {
            if (nums[left] <= nums[left-1]) {
                while (right < nums.length && nums[right] == nums[right-1]) ++right;
                
                if (right < nums.length && nums[right] > nums[right-1])
                    nums[left++] = nums[right++];
            } else {
                ++left;
                ++right;
            }
        }
        return left;
    }
}
