class Solution {
    List<List<Integer>> permutations;
    HashSet<Integer> numsSet;
    public List<List<Integer>> permute(int[] nums) {
        permutations = new ArrayList<List<Integer>>();
        numsSet = new HashSet<Integer>() {{
            for (int n : nums) add(n);
        }};
        helper(nums, new ArrayList<Integer>());
        return permutations;
    }
    
    public void helper(int[] nums, List<Integer> curr) {
        if (numsSet.isEmpty()) {
            permutations.add(new ArrayList<Integer>(curr));
            return;
        }
        
        for (int n : nums) {
            if (numsSet.contains(n)) {
                numsSet.remove(n);
                curr.add(n);
                
                helper(nums, curr);
                
                numsSet.add(n);
                curr.remove(curr.size() - 1);
            }
        }
    }
}
