class Solution {
    public int longestSubstring(String s, int k) {
        return helper(s, k, 0, s.length());
    }
    
    public int helper(String s, int k, int start, int end) {
        if (end < k) return 0;
        
        int[] currStringCounts = new int[26];
        for (int i = start; i < end; ++i) currStringCounts[s.charAt(i) - 'a'] += 1;
        for (int i = start; i < end; ++i) {
            char c = s.charAt(i);
            if (currStringCounts[c - 'a'] < k) {
                int mid = i + 1;
                while (mid < end && currStringCounts[s.charAt(mid) - 'a'] < k) ++mid;
                return Math.max(helper(s, k, start, i), helper(s, k, mid, end));
            }
        }
        return end - start;
    }
}
