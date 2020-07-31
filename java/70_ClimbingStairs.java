class Solution {
    HashMap<Integer, Integer> memo = new HashMap<>();
    public int climbStairs(int n) {
        if (n <= 1) return 1;
        else if (memo.get(n) != null) return memo.get(n);
        
        memo.put(n, climbStairs(n-1) + climbStairs(n-2));
        return memo.get(n);
    }
}
