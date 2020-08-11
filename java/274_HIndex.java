class Solution {
    public int hIndex(int[] citations) {
        Arrays.sort(citations);
        int h = 0; int N = citations.length;
        
        for (int i = 0; i < citations.length; ++i) {
            int cand = citations[i];
            if (N-cand >= i) {
                h = cand > h ? cand : h;
            }
            
            if (N-i <= cand) {
                h = N-i > h ? N-i : h;
            }
        }
        return h;
    }
}
