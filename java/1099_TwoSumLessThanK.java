class Solution {
    public int twoSumLessThanK(int[] A, int K) {
        int[] counts = new int[1001];
        for (int n : A) {
            counts[n] += 1;
        }
        
        int closeSum = -1;
        int left = 1, right = 1000;
        while (left < right) {
            if (left + right >= K || counts[right] == 0) {
                right--;
            } else {
                if (counts[left] > 0) 
                    closeSum = Math.max(left + right, closeSum);
                left++;
            }
        }
        return closeSum;
    }
}
