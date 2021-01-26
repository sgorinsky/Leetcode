class Solution {
    public int kthLargestValue(int[][] matrix, int k) {
        PriorityQueue<Integer> xorsPQ = new PriorityQueue<Integer>((a, b) -> a - b);
        int N = matrix.length, M = matrix[0].length;
        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < M; ++j) {
                matrix[i][j] ^= (i > 0 ? matrix[i-1][j] : 0) ^ (j > 0 ? matrix[i][j-1] : 0);
                xorsPQ.add(matrix[i][j]);
                if (xorsPQ.size() > k)
                    xorsPQ.poll();
                if (i < N - 1 && j < M - 1)
                    matrix[i+1][j+1] ^= matrix[i][j];
            }
        }

        return xorsPQ.peek();
    }
}

class Solution {
    public int kthLargestValue(int[][] matrix, int k) {
        PriorityQueue<Integer> xorsPQ = new PriorityQueue<Integer>((a, b) -> b - a);
        int N = matrix.length, M = matrix[0].length;
        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < M; ++j) {
                matrix[i][j] ^= (i > 0 ? matrix[i-1][j] : 0) ^ (j > 0 ? matrix[i][j-1] : 0);
                xorsPQ.add(matrix[i][j]);
                if (i < N - 1 && j < M - 1)
                    matrix[i+1][j+1] ^= matrix[i][j];
            }
        }
        
        while (--k > 0)
            xorsPQ.poll();
        
        return xorsPQ.poll();
    }
}
