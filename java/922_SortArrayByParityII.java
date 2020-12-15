class Solution {
    public int[] sortArrayByParityII(int[] A) {
        int even = 0, odd = 1;
        int[] sorted = new int[A.length];
        for (int n : A) {
            if (n % 2 == 0) {
                sorted[even] = n;
                even += 2;
            } else {
                sorted[odd] = n;
                odd += 2;
            }
        }
        return sorted;
    }
}
