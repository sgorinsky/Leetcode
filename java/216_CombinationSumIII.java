class Solution {
    List<List<Integer>> result;
    int top = 9;
    public List<List<Integer>> combinationSum3(int k, int n) {
        result = new ArrayList<List<Integer>>();
        top = Math.min(n, top);
        combine(new ArrayList<Integer>(), 0, k, n);
        return result;
    }
    
    public void combine(List<Integer> curr, int sum, int k, int n) {
        int size = curr.size();
        
        if (size == k && sum == n) {
            result.add(new ArrayList<Integer>(curr));
            return;
        } else if (size >= k || sum >= n) {
            return;
        }
        
        for (int num = size > 0 ? curr.get(size-1)+1 : 1; num <= top; ++num) {
            curr.add(num);
            combine(curr, sum + num, k, n);
            curr.remove(size);
        }
    }
}
