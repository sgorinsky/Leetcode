class Solution {
    public int removeCoveredIntervals(int[][] intervals) {
        Arrays.sort(intervals, new Comparator<int[]>() {
            @Override
            public int compare(int[] a, int[] b) {
                return a[0] == b[0] ? b[1] - a[1] : a[0] - b[0];
            }
        });
        int total = intervals.length, prevEnd = 0;
        for (int[] interval : intervals) {
            if (interval[1] <= prevEnd) {
                total--;
            } else {
                prevEnd = interval[1];
            }
        }
        return total;
    }
}
