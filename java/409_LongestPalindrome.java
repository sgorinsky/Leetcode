class Solution {
    public int longestPalindrome(String s) {
        HashMap<Character, Integer> letterCounts = new HashMap<Character, Integer>();
        
        for (int i = 0; i < s.length(); ++i) {
            Character c = s.charAt(i);
            if (letterCounts.get(c) == null) {
                letterCounts.put(c, 1);
            } else {
                letterCounts.put(c, letterCounts.get(c)+1);
            }
        }
        
        int count = 0;
        int maxOdd = 0;
        Character oddLetter = '0';
        letterCounts.put(oddLetter, 0);
        
        for (Map.Entry<Character, Integer> entry : letterCounts.entrySet()) {
            int val = entry.getValue();
            Character c = entry.getKey();
            if (entry.getValue() % 2 == 0) {
                count += entry.getValue();
            } else {
                if (val > maxOdd) {
                    count += (val - maxOdd);
                    maxOdd = val;
                    if (letterCounts.get(oddLetter) > 0) {
                        count += letterCounts.get(oddLetter) - 1;
                    }
                    oddLetter = c;
                } else {
                    count += val - 1;
                }
            }
        }
        return count;
    }
}
