class Solution {
    public int minPartitions(String n) {
        int high = 1;
        for (char c : n.toCharArray()) {
            high = Math.max(c - '0', high);
        }
        return high;
    }
}
