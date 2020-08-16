class Solution {
    private class IntervalComparator implements Comparator<int[]> {
        @Override
        public int compare(int[] a, int[] b) {
            return a[1] < b[1] ? -1 : 1;
        }
    }
    public int eraseOverlapIntervals(int[][] intervals) {
        if (intervals.length == 0)
            return 0;
        
        Arrays.sort(intervals, new IntervalComparator());
        int[] prev = intervals[0];
        int count = 0;
        
        for (int i = 1; i < intervals.length; ++i) {
            int[] curr = intervals[i];
            if (prev[1] > curr[0]) {
                if (prev[1] > curr[1]) {
                    prev = curr;
                }
                ++count;
            } else {
                prev = curr;
            }
        }
        return count;
    }
}
