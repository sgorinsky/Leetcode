class Solution {
    public int lengthOfLIS(int[] nums) {
        List<Integer> monotonicList = new ArrayList<Integer>();
        for (int n : nums) {
            if (monotonicList.isEmpty() || monotonicList.get(monotonicList.size() - 1) < n) {
                monotonicList.add(n);
            } else {
                for (int i = 0; i < monotonicList.size(); ++i) {
                    if ((n < monotonicList.get(i) && i == 0) || 
                        (n < monotonicList.get(i) && n > monotonicList.get(i-1))) {
                        monotonicList.set(i, n);
                        break;
                    }
                }
            }
        }
        return monotonicList.size();
    }
}
