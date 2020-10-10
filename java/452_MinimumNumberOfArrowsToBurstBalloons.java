class Solution {
    public int findMinArrowShots(int[][] points) {
        Arrays.sort(points, new Comparator<int[]>() {
            @Override
            public int compare(int[] a, int[] b) {
                return a[0] - b[0];
            }
        });
        
        int arrows = 0, start = -12345, end = -12345;
        for (int[] point : points) {
            if (point[0] >= start && point[0] <= end) {
                end = Math.min(point[1], end);
            } else {
                arrows += 1;
                start = point[0];
                end = point[1];
            }
        }
        return arrows;
    }
}
