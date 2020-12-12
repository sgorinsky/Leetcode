class Solution {
    public int removeDuplicates(int[] nums) {
        int count = 1, j = 1;
        for (int i = 1; i < nums.length; ++i){
            count = nums[i] == nums[i - 1] ? count + 1 : 1;
            if (count < 3) nums[j++] = nums[i];
        }
        return j;
    }
}
