class Solution {
    public int[] dailyTemperatures(int[] T) {
        Stack<int[]> stack = new Stack<int[]>();
        int[] results = new int[T.length];
        for (int i = 0; i < T.length; ++i) {
            if (!stack.isEmpty() && stack.peek()[1] < T[i]) {
                while (!stack.isEmpty() && stack.peek()[1] < T[i]) {
                    int[] pastTemp = stack.pop();
                    results[pastTemp[0]] = i - pastTemp[0];
                }
            }
            stack.add(new int[]{i, T[i]});
        }
        return results;
    }
}
