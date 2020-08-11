class Solution {
    public int oddEvenJumps(int[] A) {
        int N = A.length;
        if (N <= 1) return N;
        boolean[] odd = new boolean[N];
        boolean[] even = new boolean[N];
        TreeMap<Integer, Integer> vals = new TreeMap<Integer, Integer>();
        
        odd[N-1] = even[N-1] = true;
        vals.put(A[N-1], N-1);
        
        for (int i = N-2; i >= 0; --i) {
            if (vals.containsKey(A[i])) { // same element so we take the val of the next transplant outcome of next possible jump
                odd[i] = even[vals.get(A[i])];
                even[i] = odd[vals.get(A[i])];
            } else {
                Integer lower = vals.lowerKey(A[i]);
                Integer higher = vals.higherKey(A[i]);
                
                if (lower != null) even[i] = odd[vals.get(lower)];
                if (higher != null) odd[i] = even[vals.get(higher)];
            }
            vals.put(A[i], i);
        }
        
        int count = 0;
        for (boolean b: odd) {
            if (b) ++count;
        }
        return count;
    }
}
