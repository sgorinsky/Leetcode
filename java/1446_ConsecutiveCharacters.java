class Solution {
    public int maxPower(String s) {
        if (s.isEmpty()) return 0;
        Character last = s.charAt(0);
        int high = 1, curr = 1;
        for (int i = 1; i < s.length(); ++i) {
            Character c = s.charAt(i);
            if (c == last) curr++;
            else {
                last = c;
                curr = 1;
            }
            high = Math.max(curr, high);
        }
        return high;
    }
}
