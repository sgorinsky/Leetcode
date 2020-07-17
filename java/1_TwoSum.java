class Solution {
    public int[] twoSum(int[] nums, int target) {
        HashMap<Integer, Integer> numIndices = new HashMap<>();
        for (int i = 0; i < nums.length; ++i) {
            if (numIndices.containsKey(target-nums[i])) {
                return new int[] {numIndices.get(target-nums[i]), i};
            }
            numIndices.put(nums[i], i);
        }
        return new int[] {-1, -1};
    }
}
