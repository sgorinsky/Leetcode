class Solution {
    public int[] asteroidCollision(int[] asteroids) {
        Stack<Integer> stack = new Stack();
        for (int asteroid : asteroids) {
            boolean brokeFromWhileLoop = false;
            while (!stack.isEmpty() && asteroid < 0 && stack.peek() > 0) {
                if (-asteroid > stack.peek()) {
                    stack.pop();
                    continue;
                } else if (-asteroid == stack.peek()) {
                    stack.pop();
                }
                brokeFromWhileLoop = true;
                break;
            }
            if (!brokeFromWhileLoop) stack.add(asteroid);
        }
        int[] result = new int[stack.size()];
        for (int i = 0; i < result.length; ++i) result[i] = stack.get(i);
        return result;
    }
}
