class Solution {
    List<List<Integer>> results;
    public List<List<Integer>> combine(int n, int k) {
        results = new ArrayList<List<Integer>>();
        helper(new ArrayList<Integer>(), 1, n, k);
        return results;
    }
    
    public void helper(List<Integer> curr, int start, int n, int k) {
        if (curr.size() == k) {
            results.add(new ArrayList<Integer>(curr));
        } else {
            for (int i = start; i <= n; ++i) {
                curr.add(i);
                helper(curr, i + 1, n, k);
                curr.remove(curr.size() - 1);
            }
        }
    }
}
