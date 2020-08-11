class Solution {
    public int balancedStringSplit(String s) {
        int score = 0; int count = 0;
        for (int i = 0; i< s.length(); ++i) {
            score += s.charAt(i) == 'L' ? 1 : -1;
            if (score == 0) ++count;
        }
        return count;
    }
}
