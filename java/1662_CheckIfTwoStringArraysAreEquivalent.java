class Solution {
    public boolean arrayStringsAreEqual(String[] word1, String[] word2) {
        int idx1 = 0, idx2 = 0;
        int a = 0, b = 0;
        while (idx1 < word1.length && idx2 < word2.length) {
            while (a < word1[idx1].length() && b < word2[idx2].length()) {
                if (word1[idx1].charAt(a++) != word2[idx2].charAt(b++)) return false;
            }
            if (a >= word1[idx1].length()) {
                idx1++;
                a = 0;
            }
            if (b >= word2[idx2].length()) {
                idx2++;
                b = 0;
            }
        }
        return idx1 == word1.length && idx2 == word2.length;
    }
}
