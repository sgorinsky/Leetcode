class Solution {
    List<String> parentheses = new ArrayList<String>();
    public List<String> generateParenthesis(int n) {
        helper("", 0, 0, n);
        return parentheses;
    }
    
    public void helper(String curr, int left, int right, int n) {
        if (curr.length() == 2 * n) parentheses.add(curr);
        else {
            if (left < n) helper(curr + "(", left + 1, right, n);
            if (right < left) helper(curr + ")", left, right + 1, n);
        }
    }
}
