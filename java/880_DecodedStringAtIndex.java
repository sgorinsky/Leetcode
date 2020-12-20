class Solution {
    public String decodeAtIndex(String S, int k) {
        long size = 0;
        for (char c : S.toCharArray()) {
            if (Character.isDigit(c)) {
                size *= c - '0';
            } else {
                size++;
            }
        }
        
        int N = S.length();
        for (int i = N - 1; i >= 0; --i) {
            char c = S.charAt(i);
            k %= size;
            if (Character.isLetter(c)) {
                if (k == 0) return "" + c;
                else size--;
            } else {
                size /= c - '0';
            }
        }
        return S.substring(0, 1);
    }
}
