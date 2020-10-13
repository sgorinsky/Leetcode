class Solution {
    public boolean buddyStrings(String A, String B) {
        if (A.length() != B.length()) return false;
        HashMap<Character, Integer> ACounts = new HashMap<Character,Integer>();
        HashMap<Character, Integer> BCounts = new HashMap<Character,Integer>();
        
        
        int count = 0;
        for (int i = 0; i < A.length(); ++i) {
            Character charA = A.charAt(i), charB = B.charAt(i);
            if (charA != charB) ++count;
            
            ACounts.put(charA, ACounts.getOrDefault(charA, 0) + 1);
            BCounts.put(charB, BCounts.getOrDefault(charB, 0) + 1);
        }
        if (count == 2) {
            
            for (Character key : ACounts.keySet()) {
                int valA = ACounts.getOrDefault(key, 0), valB = BCounts.getOrDefault(key, 0); // really strange, need int here b/c even if two Integers have the same value, they are != apparently
                if (valA != valB) return false;
            }
            return true;
        } else if (count == 0) {
            for (Integer value : ACounts.values())
                if (value >= 2) return true;
        }
        
        return false;
    }
}
