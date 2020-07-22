class Solution {
    public int[] intersect(int[] nums1, int[] nums2) {
        int[] bigger;
        int[] smaller;
        if (nums1.length > nums2.length) {
            bigger = nums1; smaller = nums2;
        } else {
            bigger = nums2; smaller = nums1;
        }
        
        HashMap<Integer, Integer> numCounts = new HashMap<Integer, Integer>();
        for (int n : smaller) {
            numCounts.put(n, numCounts.getOrDefault(n, 0) + 1);
        }
        
        int k = 0;
        List<Integer> resList = new ArrayList<Integer>();
        for (int n : bigger) {
            if (numCounts.get(n) != null && numCounts.get(n) != 0) {
                bigger[k++] = n;
                numCounts.put(n, numCounts.get(n)-1);
            }
        }
        return Arrays.copyOfRange(bigger, 0, k);
    }
}
