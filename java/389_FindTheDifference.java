class Solution {
    public char findTheDifference(String s, String t) {
        HashMap<Character, Integer> letterCounts = new HashMap<Character, Integer>();
        for (char c : s.toCharArray())
            letterCounts.put(c, letterCounts.getOrDefault(c, 0) + 1);
        
        for (char c : t.toCharArray()) {
            if (letterCounts.get(c) == null || letterCounts.get(c) == 0) 
                return c;
            else
                letterCounts.put(c, letterCounts.get(c) - 1);
        }
        return s.charAt(0);
    }
}
