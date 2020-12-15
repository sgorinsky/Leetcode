class Solution {
    public int[] searchRange(int[] nums, int target) {
        int[] range = {-1, -1};
        if (nums.length == 0) return range;
        
        int left = binarySearch(nums, target, false);
        if (nums[left] != target) return range;
        range[0] = left;
        range[1] = binarySearch(nums, target, true);
        return range;
    }
    
    public int binarySearch(int[] nums, int target, boolean findRight) {
        int left = 0, right = nums.length - 1;
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] < target || (findRight && nums[mid] == target)) left = mid + 1;
            else right = mid;
        }
        return nums[right] == target || right == 0 ? right : right - 1;
    }
}
