class Solution {
    public int maxNumberOfApples(int[] arr) {
        Arrays.sort(arr);
        int total = 5000; int count = 0;
        for (int apple : arr) {
            if (total - apple < 0) {
                break;
            } else {
                total -= apple; ++count;
            }
        }
        return count;
    }
}
