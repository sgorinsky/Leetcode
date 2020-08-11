class Solution {
    List<List<Integer>> res = new ArrayList<List<Integer>>();
    int[] cands;
    public List<List<Integer>> combinationSum(int[] candidates, int target) {
        cands = candidates;
        List<Integer> curr = new ArrayList<Integer>();
        return helper(curr, 0, 0, target);
    }
    
    List<List<Integer>> helper(List<Integer> curr, int sum, int idx, int target) {
        if (sum == target) {
            res.add(curr);
            return res;
        } else if (sum > target) {
            return res;
        }
        
        for (int i = idx; i < cands.length; ++i) {
            int cand = cands[i];
            curr.add(cand);
            helper(new ArrayList<Integer>(curr), sum+cand, i, target);
            curr.remove(curr.size()-1);
        }
        return res;
    }
    
}
