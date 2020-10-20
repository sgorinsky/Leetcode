class Solution {
    public int minDominoRotations(int[] A, int[] B) {
        int rotations = checkRotations(A[0], A, B);
        return rotations != -1 || A[0] == B[0] ? rotations : checkRotations(B[0], A, B);
    }
    
    public int checkRotations(int target, int[] A, int[] B) {
        int upperRotations = 0, lowerRotations = 0;
        for (int i = 0; i < A.length; ++i) {
            if (A[i] != target && B[i] != target) return -1;
            else if (A[i] != target) upperRotations++;
            else if (B[i] != target) lowerRotations++;
        }
        return Math.min(upperRotations, lowerRotations);
    }
}
