class Solution {
    public int[] sortedSquares(int[] A) {
        List<Integer> negStack = new ArrayList<Integer>();
        int idx = 0, numNegs = 0;
        
        while (idx < A.length && A[idx] < 0) {
            negStack.add(A[idx]*A[idx]);
            ++idx; ++numNegs;
        }
        
        int[] res = new int[A.length];
        int resIdx = 0;
        for (int i = numNegs; i < A.length; ++i) {
            int square = A[i] * A[i];
            while (!negStack.isEmpty() && square > negStack.get(numNegs-1)) {
                res[resIdx++] = negStack.remove(numNegs-- - 1);
            }
            res[resIdx++] = square;
        }
        while (!negStack.isEmpty()) {
            res[resIdx++] = negStack.remove(numNegs-- - 1);
        }
        return res;
    }
}
