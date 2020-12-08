class Solution {
    public int numPairsDivisibleBy60(int[] time) {
        int[] moddedTimes = new int[60];
        int count = 0;
        for (int t : time) moddedTimes[t % 60] += 1;
        for (int t = 0; t <= 30; ++t) {
            if (t == 0 || t == 30) {
                for (int x = 2; x <= moddedTimes[t]; ++x) {
                    count += (x - 1);
                }
            } else {
                count += (moddedTimes[t] * moddedTimes[60 - t]);
            }
        }
        return count;
    }
}
