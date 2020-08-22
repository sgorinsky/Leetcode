class Solution {
    public int removeDuplicates(int[] nums) {
        int i = 0;
        for (int j = 1; j < nums.length; ++j) {
            if (nums[j] != nums[i])
                nums[++i] = nums[j];
        }
        return i+1;
    }
}

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
