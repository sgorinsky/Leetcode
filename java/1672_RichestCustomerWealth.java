class Solution {
    public int maximumWealth(int[][] accounts) {
        int high = 0;
        for (int[] account : accounts) {
            int curr = 0;
            for (int n : account) {
                curr += n;
            }
            high = Math.max(high, curr);
        }
        return high;
    }
}
