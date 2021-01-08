class Solution {
    public int lengthOfLongestSubstring(String s) {
        int[] letters = new int[128];
        Arrays.fill(letters, -1);
        int high = 0, idx = 0;
        for (int i = 0; i < s.length(); ++i) {
            char c = s.charAt(i);
            if (letters[c] >= 0) 
                idx = Math.max(letters[c] + 1, idx);
            letters[c] = i;
            high = Math.max(high, i - idx + 1);
        }
        return high;
    }
}
