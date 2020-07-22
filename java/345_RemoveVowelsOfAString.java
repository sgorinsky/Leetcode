class Solution {
    Set<Character> vowels = new HashSet<Character>(Arrays.asList('a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'));
    public String reverseVowels(String s) {
        String str = "";
        List<Character> vowelStack = new ArrayList<Character>();
        for (int i = 0; i < s.length(); ++i) {
            if (vowels.contains(s.charAt(i))) {
                vowelStack.add(s.charAt(i));
            }
        }
        for (int i = 0; i < s.length(); ++i) {
            if (vowels.contains(s.charAt(i))) {
                str += vowelStack.remove(vowelStack.size()-1);
            } else {
                str += s.charAt(i);
            }
        }
        return str;
        
    }
}
