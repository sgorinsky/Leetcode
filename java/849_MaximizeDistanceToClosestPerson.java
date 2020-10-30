class Solution {
    public int maxDistToClosest(int[] seats) {
        int left = 0, right = 0, highest = 0;
        int N = seats.length;
        while (right < N && seats[right] == 0) {
            right++;
            highest++;
        }
        for (int i = 0; i < N; ++i) {
            if (seats[i] == 1) {
                right = i + 1;
                left = i;
                while (right < N && seats[right] == 0) right++;
                if (right == N) return Math.max(highest, right - 1 - i);
            } else {
                highest = Math.max(highest, Math.min(i - left, right - i));
            }
        }
        return highest;
    }
}
