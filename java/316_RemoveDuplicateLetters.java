class Solution {
    public String removeDuplicateLetters(String s) {
        HashMap<Character, Integer> letterCounts = new HashMap<Character, Integer>();
        for (int i = 0; i < s.length(); ++i) letterCounts.put(s.charAt(i), letterCounts.getOrDefault(s.charAt(i), 0) + 1);
        
        List<Character> letterStack = new ArrayList<Character>();
        HashSet<Character> isInStack = new HashSet<Character>();
        for (int i = 0; i < s.length(); ++i) {
            Character c = s.charAt(i);
            if (!isInStack.contains(c)) {
                while (!letterStack.isEmpty() && c < letterStack.get(letterStack.size() - 1) && letterCounts.get(letterStack.get(letterStack.size() - 1)) > 0) {
                    isInStack.remove(letterStack.get(letterStack.size() - 1));
                    letterStack.remove(letterStack.size() - 1);
                }
                letterStack.add(c);
                isInStack.add(c);
            }
            letterCounts.put(c, letterCounts.get(c) - 1);
        }
        StringBuilder sb = new StringBuilder();
        for (Character c : letterStack) sb.append(c);
        return sb.toString();
    }
}
