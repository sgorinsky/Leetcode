class Solution {
    HashMap<Integer, Integer> cache = new HashMap<Integer, Integer>();
    public int numDecodings(String s) {
        return helper(s, 0);
    }
    
    public int helper(String s, int head) {
        if (cache.get(head) != null) {
            return cache.get(head);
        } else if (head == s.length()) { 
            return 1;
        } else if (head > s.length() || s.charAt(head) == '0') {
            return 0;
        }
        
        cache.put(head, helper(s, head + 1));
        if (head + 2 <= s.length()) {
            int digitSum = (s.charAt(head) - '0') * 10 + (s.charAt(head + 1) - '0');
            if (digitSum >= 0 && digitSum <= 26) {
                cache.put(head, cache.get(head) + helper(s, head + 2));
            }
        }
        return cache.get(head);
    }
}
