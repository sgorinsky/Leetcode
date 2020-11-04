class Solution {
    int[][] directions = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
    public int[][] floodFill(int[][] image, int sr, int sc, int newColor) {
        Queue<int[]> q = new LinkedList<int[]>();
        q.add(new int[]{sr, sc});
        
        int startColor = image[sr][sc];
        image[sr][sc] = newColor;
        while (!q.isEmpty()) {
            int[] indices = q.remove();
            int i = indices[0], j = indices[1];
            for (int[] direction : directions) {
                int r = i + direction[0], c = j + direction[1];
                if (canTravelTo(image, r, c, startColor, newColor)) {
                    image[r][c] = newColor;
                    q.add(new int[]{r, c});
                }
            }
        }
        return image;
    }
    
    private boolean canTravelTo(int[][] image, int r, int c, int startColor, int newColor) {
        return r >= 0 && r < image.length && c >= 0 && c < image[0].length && image[r][c] != newColor && image[r][c] == startColor;
    }
}
