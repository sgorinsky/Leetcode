class Solution {
    public boolean isPalindrome(String s) {
        int left = 0; int right = s.length()-1;
        while (left < right) {
            if (!Character.isLetter(s.charAt(left)) && !Character.isDigit(s.charAt(left))) {
                while (left < s.length() && !Character.isLetter(s.charAt(left)) && !Character.isDigit(s.charAt(left))) ++left;
            }
            if (!Character.isLetter(s.charAt(right)) && !Character.isDigit(s.charAt(right))) {
                while (right >= 0 && !Character.isLetter(s.charAt(right)) && !Character.isDigit(s.charAt(right))) --right;
            }
            
            if (left < s.length() && right >= 0 && Character.toLowerCase(s.charAt(left++)) != Character.toLowerCase(s.charAt(right--))) return false;
        }
        return true;
    }
}
