class Solution {
    HashMap<Integer, Integer> letters;
    public int titleToNumber(String s) {
        letters = new HashMap<Integer, Integer>();
        int intA = 'A';
        for (int i = 0; i < 26; ++i) letters.put(intA + i, i+1);
        
        int total = 0;
        int power = s.length()-1;
        
        for (int i = 0; i < s.length(); ++i) {
            int c = s.charAt(i);
            total += Math.pow(26, power--) * letters.get(c);
        }
        return (int) total;
    }
}
