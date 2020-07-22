class Solution {
    public int findNumbers(int[] nums) {
        int count = 0;
        for (int n : nums) {
            int iterations = 0;
            while (n > 0) {
                n = Math.floorDiv(n, 10);
                ++iterations;
            }
            if (iterations % 2 == 0) ++count;
        }
        return count;
    }
}
