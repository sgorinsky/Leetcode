class Solution {
    public int shortestDistance(String[] words, String word1, String word2) {
        int idx = 100000, jdx = -100000;
        int minDist = Math.abs(jdx - idx);
        
        for (int i = 0; i < words.length; ++i) {
            String currWord = words[i];
            if (word1.equals(currWord)) idx = i;
            else if (word2.equals(currWord)) jdx = i;
            minDist = Math.min(minDist, Math.abs(jdx - idx));
        }
        return minDist;
    }
}
