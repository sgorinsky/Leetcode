class Solution {
    int biggest = 0;
    public int largestRectangleArea(int[] heights) {
        divideAndConquer(heights, 0, heights.length - 1);
        return biggest;
    }
    
    public void divideAndConquer(int[] heights, int start, int end) {
        if (start > end) return;
        
        int small = heights[start], smallIdx = start;
        for (int i = start; i <= end; ++i) {
            if (heights[i] < small) {
                small = heights[i];
                smallIdx = i;
            }
        }
        biggest = Math.max(small * (end - start + 1), biggest);
        divideAndConquer(heights, start, smallIdx - 1);
        divideAndConquer(heights, smallIdx + 1, end);
    }
}
