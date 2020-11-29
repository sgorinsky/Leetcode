class Solution {
    public int[] mostCompetitive(int[] nums, int k) {
        int N = nums.length;
        List<Integer> stack = new ArrayList<Integer>();
        for (int i = 0; i < N; ++i) {
            int num = nums[i];
            while (!stack.isEmpty() && N - i + stack.size() > k && num < stack.get(stack.size() - 1)) {
                stack.remove(stack.size() - 1);
            }
            stack.add(num);
        }
        
        while (stack.size() > k) stack.remove(stack.size() - 1);
        int[] result = new int[stack.size()];
        for (int i = 0; i < result.length; ++i) result[i] = stack.get(i);
        return result;
    }
}
