/**
 * // This is the BinaryMatrix's API interface.
 * // You should not implement it, or speculate about its implementation
 * interface BinaryMatrix {
 *     public int get(int row, int col) {}
 *     public List<Integer> dimensions {}
 * };
 */

class Solution {
    public int leftMostColumnWithOne(BinaryMatrix binaryMatrix) {
        List<Integer> dimensions = binaryMatrix.dimensions();
        int leftMost = -1;
        for (int i = 0; i < dimensions.get(0); ++i) {
            int j;
            if (leftMost == -1) {
                j = dimensions.get(1)-1;
            } else {
                j = leftMost;
            }
            while (j >= 0 && binaryMatrix.get(i, j) == 1) {
                leftMost = j;
                --j;
            }
        }
        return leftMost;
    }
}
