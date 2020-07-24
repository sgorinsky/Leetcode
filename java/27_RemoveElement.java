class Solution {
    public int removeElement(int[] nums, int val) {
        int length = nums.length;
        for (int i = 0; i < length; ++i) {
            if (length > 0 && nums[i] == val) {
                for (int j = i+1; j < length; ++j) nums[j-1] = nums[j];
                --length; --i;
            }
        }
        return length;
    }
}
