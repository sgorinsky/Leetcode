class Solution {
    public String getHint(String secret, String guess) {
        HashMap<Character, Integer> counts = new HashMap<Character, Integer>();
        int bulls = 0, cows = 0;
        for (int i = 0; i < secret.length(); ++i) {
            char s = secret.charAt(i), g = guess.charAt(i);
            if (s == g) {
                ++bulls;
            } else {
                if (counts.getOrDefault(s, 0) < 0) ++cows;
                if (counts.getOrDefault(g, 0) > 0) ++cows;
                
                // secret and guess keys modify distance from 0 vals
                counts.put(s, counts.getOrDefault(s, 0) + 1);
                counts.put(g, counts.getOrDefault(g, 0) - 1);
            }
        }
        return bulls + "A" + cows + "B";
    }
}
