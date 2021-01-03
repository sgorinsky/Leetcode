class Solution {
    int high = 1000000007;
    public int countPairs(int[] deliciousness) {
        HashMap<Integer, Integer> counts = new HashMap<Integer, Integer>();
        int pairs = 0;
        for (int n : deliciousness) {
            counts.put(n, counts.getOrDefault(n, 0) + 1);
            for (int i = 0; i < 22; ++i) {
                # int l = (p - n) % high;
		int l = ((1 << i) - n) % high; // slightly faster w bitwise shift
                p *= 2;
                if (counts.get(l) != null) {
                    pairs = (pairs + counts.get(l) - (l == n ? 1 : 0)) % high;
                }
            }
        }
        return pairs;
    }
}
