class Solution {
    List<List<Integer>> res;
    public List<List<Integer>> permuteUnique(int[] nums) {
        res = new ArrayList<List<Integer>>();
        Arrays.sort(nums);
        return backtrack(nums, new ArrayList<Integer>());
    }
    
    public List<List<Integer>> backtrack(int[] nums, List<Integer> curr) {
        if (nums.length == curr.size()) {
            res.add(new ArrayList<Integer>(curr));
            return res;
        }
        
        for (int i = 0; i < nums.length; ++i) {
            if (nums[i] != -11 && (i == 0 || nums[i] != nums[i-1])) {
                int temp = nums[i];
                nums[i] = -11;
                curr.add(temp);
                backtrack(nums, curr);
                curr.remove(curr.size() - 1);
                nums[i] = temp;
            }
        }
        return res;
    }
}
