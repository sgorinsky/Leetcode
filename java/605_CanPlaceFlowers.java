class Solution {
    public boolean canPlaceFlowers(int[] flowerbed, int n) {
        int N = flowerbed.length;
        for (int i = 0; i < N; ++i) {
            if (flowerbed[i] == 0 && (i == 0 || flowerbed[i-1] == 0) && (i == N - 1 || flowerbed[i+1] == 0)) {
                n--;
                flowerbed[i++] = 1;
                if (n == 0) break;
            }
        }
        return n <= 0;
    }
}
