class Solution {
    public List<String> summaryRanges(int[] nums) {
        List<String> results = new ArrayList<String>();
        if (nums.length == 0) return results;
        int low = nums[0], high = nums[0];
        for (int n : nums) {
            if (n > high + 1) {
                results.add(high == low ? "" + high : low + "->" + high);
                low = n;
                high = n;
            } else {
                high = n;
            }
        }
        results.add(high == low ? "" + high : low + "->" + high);
        return results;
    }
}
