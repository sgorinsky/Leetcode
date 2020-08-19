class Solution {
    public int[] numsSameConsecDiff(int N, int K) {

        if (N == 1)
            return new int[] {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
        
        Deque<Integer> q = new LinkedList<Integer>();
        for (int i = 1; i <= 9; ++i)
            q.add(i);
        
        for (int i = 1; i < N; ++i) {
            Deque<Integer> nextQ = new LinkedList<Integer>();
            while (!q.isEmpty()) {
                int n = q.poll();
                int d = n % 10;
                
                if (d - K >= 0)
                    nextQ.add(n*10 + (d-K));
                
                if (K != 0 && d + K <= 9)
                    nextQ.add(n*10 + (d+K));
            }
            q = nextQ;
        }
        
        int[] result = new int[q.size()];
        int idx = 0;
        while (!q.isEmpty())
            result[idx++] = q.poll();
        
        return result;
    }
}
