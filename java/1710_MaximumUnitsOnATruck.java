class Solution {
public
    int maximumUnits(int[][] boxTypes, int truckSize) {
        PriorityQueue<int[]> queue = new PriorityQueue<int[]>((a, b)->b[1] - a[1]);
        queue.addAll(Arrays.asList(boxTypes));
        int unitCount = 0;
        while (truckSize > 0 && !queue.isEmpty()) {
            int[] top = queue.poll();
            int boxCount = Math.min(truckSize, top[0]);
            unitCount += boxCount * top[1];
            truckSize -= boxCount;
        }
        return unitCount;
    }
}
