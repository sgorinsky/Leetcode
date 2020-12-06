class Solution {
    public int maxOperations(int[] nums, int k) {
        HashMap<Integer, Integer> numCounts = new HashMap<Integer, Integer>();
        int count = 0;
        for (int n : nums) {
            int complement = k - n;
            if (numCounts.getOrDefault(complement, 0) > 0) {
                numCounts.put(complement, numCounts.get(complement) - 1);
                count++;
            } else {
                numCounts.put(n, numCounts.getOrDefault(n, 0) + 1);
            }
        }
        return count;
    }
}
