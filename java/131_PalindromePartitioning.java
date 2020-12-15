class Solution {
    List<List<String>> partitionCombinations;
    public List<List<String>> partition(String s) {
        partitionCombinations = new ArrayList<List<String>>();
        List<String> candidatePalindromes = new ArrayList<String>();
        helper(s, candidatePalindromes, 0);
        return partitionCombinations;
    }
    
    public void helper(String s, List<String> curr, int start) {
        if (start >= s.length()) {
            partitionCombinations.add(new ArrayList<String>(curr));
            return;
        }
        
        for (int i = start; i < s.length(); ++i) {
            if (isPalindrome(s, start, i)) {
                curr.add(s.substring(start, i + 1));
                helper(s, curr, i + 1);
                curr.remove(curr.size() - 1);
            }
        }
    }
    
    public boolean isPalindrome(String s, int startIdx, int endIdx) {
        while (startIdx < endIdx) {
            if (s.charAt(startIdx++) != s.charAt(endIdx--)) return false;
        }
        return true;
    }
}
