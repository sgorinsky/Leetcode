class Solution {
    public int lengthOfLastWord(String s) {
        int i = s.length(), length = 0;
        
        while (i > 0) {
            i--;
            if (s.charAt(i) != ' ')
                ++length;
            else if (length > 0)
                return length;
        }
        return length;
    }
}
