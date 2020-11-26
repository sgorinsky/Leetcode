class Solution {
    String[] digitMap = {"abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
    List<String> letterCombinations = new ArrayList<String>();
    public List<String> letterCombinations(String digits) {
        if (digits.length() == 0) return letterCombinations;
        helper(0, digits, "");
        return letterCombinations;
    }
    
    public void helper(int start, String digits, String currentLetters) {
        if (currentLetters.length() == digits.length()) {
            letterCombinations.add(currentLetters);
            return;
        }
        
        for (int i = start; i < digits.length(); ++i) {
            char digit = digits.charAt(i);
            int idx = digit - '0' - 2;
            for (char l : digitMap[idx].toCharArray()) {
                helper(i + 1, digits, currentLetters + l);
            }
        }
    }
}
