class Solution {
    public int[] numsSameConsecDiff(int N, int K) {

        if (N == 1)
            return new int[] {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
        
        List<Integer> q = Arrays.asList(1, 2, 3, 4, 5, 6, 7, 8, 9);
        for (int i = 1; i < N; ++i) {
            ArrayList<Integer> nextQ = new ArrayList<Integer>();
            for (int n : q) {
                int tail = n % 10;
                ArrayList<Integer> digits = new ArrayList<Integer>();
                
                if (tail + K <= 9)
                    digits.add(tail+K);
                
                if (K != 0 && tail-K >= 0)
                    digits.add(tail-K);
                
                for (int d : digits)
                    nextQ.add(n*10 + d);
            }
            q = nextQ;
        }
        
        int[] result = new int[q.size()];
        int idx = 0;
        for (int n : q)
            result[idx++] = n;
        
        return result;
    }
       
}
