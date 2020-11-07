class Solution {
    public int[] sortArray(int[] nums) {
        return split(nums, 0, nums.length - 1);
    }
    
    public int[] split(int[] nums, int start, int end) {
        if (start == end) return new int[]{nums[start]};
        
        int[] firstHalf = split(nums, start, (start + end) / 2);
        int[] secondHalf = split(nums, (start + end) / 2 + 1, end);
        
        return merge(firstHalf, secondHalf);
    }
    
    public int[] merge(int[] a, int[] b) {
        int left = 0, right = 0;
        int[] mergedArray = new int[a.length + b.length];
        while (left < a.length || right < b.length) {
            if (right >= b.length || (left < a.length && a[left] < b[right])) {
                mergedArray[left + right] = a[left++];
            } else {
                mergedArray[left + right] = b[right++];
            }
        }
        return mergedArray;
    }
}
