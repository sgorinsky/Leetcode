class Solution {
    public int findPoisonedDuration(int[] timeSeries, int duration) {
        int total = 0, end = 0;
        for (int t : timeSeries) {
            total += Math.min(t + duration - end, duration);
            end = t + duration;
        }
        return total;
    }
}
