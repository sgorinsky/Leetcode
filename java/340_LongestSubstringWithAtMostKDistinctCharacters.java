class Solution {
    public int lengthOfLongestSubstringKDistinct(String s, int k) {
        if (s.length()*k == 0) return 0;
        
        HashMap<Character, Integer> letCounts = new HashMap<Character, Integer>();
        int kCount = 0, trailingIdx = 0, highCount = 1;
        
        for (int i = 0; i < s.length(); ++i) {
            if (letCounts.get(s.charAt(i)) == null || letCounts.get(s.charAt(i)) == 0) {
                ++kCount;
                letCounts.put(s.charAt(i), 1);
            } else {
                letCounts.put(s.charAt(i), letCounts.get(s.charAt(i))+1);
            }
            
            
            while (trailingIdx < s.length() && kCount > k) {
                char first = s.charAt(trailingIdx);
                while (trailingIdx < s.length() && first == s.charAt(trailingIdx)) {
                    ++trailingIdx;
                    letCounts.put(first, letCounts.get(first)-1);
                }
                    
                if (letCounts.get(first) == 0) --kCount;
            }
            if (highCount < i-trailingIdx+1) highCount = i-trailingIdx+1;
        }
        return highCount;
    }
}
