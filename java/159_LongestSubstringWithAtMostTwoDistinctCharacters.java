class Solution {
    public int lengthOfLongestSubstringTwoDistinct(String s) {
        HashMap<Character, Integer> letterCounts = new HashMap<Character, Integer>(){{
            char[] startingPoints = {'a', 'A'};
            for (char c : startingPoints) {
                for (int i = 0; i < 26; ++i) {
                    put((char) (c + i), 0);
                }
            }
        }};
        
        int trailIdx = 0, maxLength = 0, currentLength = 0, distinctCharCount = 0;
        for (int i = 0; i < s.length(); ++i) {
            char currChar = s.charAt(i);
            currentLength++;
            letterCounts.put(currChar, letterCounts.get(currChar) + 1);
            if (letterCounts.get(currChar) == 1) distinctCharCount++;
            while (distinctCharCount > 2) {
                char trailChar = s.charAt(trailIdx++);
                letterCounts.put(trailChar, letterCounts.get(trailChar) - 1);
                if (letterCounts.get(trailChar) == 0) distinctCharCount--;
                currentLength--;
            }
            maxLength = Math.max(currentLength, maxLength);
        }
        return maxLength;
    }
}
