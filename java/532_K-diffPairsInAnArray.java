class Solution {
    public int findPairs(int[] nums, int k) {
        HashMap<Integer, Integer> rollingNumCounts = new HashMap<Integer, Integer>();
        int count = 0;
        for (int n : nums) {
            int nCount = rollingNumCounts.getOrDefault(n, 0);
            if (k != 0) {
                if (nCount == 0) {
                    if (rollingNumCounts.getOrDefault(n - k, 0) > 0) ++count;
                    if (rollingNumCounts.getOrDefault(n + k, 0) > 0) ++count;
                }
            } else if (rollingNumCounts.getOrDefault(n, 0) == 1) 
                ++count;
            rollingNumCounts.put(n, nCount + 1);
        }
        return count;
    }
}
