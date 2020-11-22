class Solution {
    String[] codes = {".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."};
    public int uniqueMorseRepresentations(String[] words) {
        HashSet<String> uniques = new HashSet<String>();
        for (String word : words) {
            String currCode = "";
            for (Character c : word.toCharArray()) {
                currCode += codes[c - 'a'];
            }
            uniques.add(currCode);
        }
        return uniques.size();
    }
}
