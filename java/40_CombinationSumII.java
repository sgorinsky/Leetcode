class Solution {
    public List<List<Integer>> combinationSum2(int[] candidates, int target) {
        Arrays.sort(candidates);
        List<List<Integer>> result = new ArrayList<List<Integer>>();
        
        combine(new ArrayList<Integer>(), 0, 0, target, result, candidates);
        return result;
    }
    
    public void combine(List<Integer> curr, int sum, int start, int target, List<List<Integer>> result, int[] candidates) {
        int size = curr.size();
        if (sum == target) {
            result.add(new ArrayList<Integer>(curr));
            return;
        } else if (sum > target) {
            return;
        }
        
        for (int i = start; i < candidates.length; ++i) {
            if (i > start && candidates[i] == candidates[i-1])
                continue;
            
            int n = candidates[i];
            curr.add(n);
            combine(curr, sum + n, i + 1, target, result, candidates);
            curr.remove(size);
        }
    }
}
