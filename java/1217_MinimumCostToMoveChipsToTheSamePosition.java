class Solution {
    public int minCostToMoveChips(int[] positions) {
        int evens = 0, odds = 0;
        for (int p : positions) {
            if (p % 2 == 0) evens++;
            else odds++;
        }
        return Math.min(odds, evens);
    }
}
