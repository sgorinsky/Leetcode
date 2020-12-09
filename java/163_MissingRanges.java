class Solution {
    public List<String> findMissingRanges(int[] nums, int lower, int upper) {
        List<String> missingRanges = new ArrayList<String>();
        if (nums.length == 0) {
            if (lower == upper) missingRanges.add("" + lower);
            else missingRanges.add(lower + "->" + upper);
        }
        for (int i = 0; i < nums.length; ++i) {
            if (i == 0) {
                if (nums[i] - 1 > lower) missingRanges.add(lower + "->" + (nums[i] - 1));
                else if (nums[i] - 1 == lower) missingRanges.add("" + lower);
            } else {
                if (nums[i - 1] + 1 == nums[i] - 1) missingRanges.add("" + (nums[i] - 1));
                else if (nums[i - 1] + 1 != nums[i]) missingRanges.add((nums[i - 1] + 1) + "->" + (nums[i] - 1));
            }
            if (i == nums.length - 1) {
                if (nums[i] + 1 == upper) missingRanges.add("" + upper);
                else if (nums[i] + 1 < upper) missingRanges.add((nums[i] + 1) + "->" + upper);
            }
        }
        return missingRanges;
    }
}
