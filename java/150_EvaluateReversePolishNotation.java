class Solution {
    
    private static final Map<String, BiFunction<Integer, Integer, Integer>> OPERATIONS = new HashMap<>() {{
        put("+", (a, b) -> a + b);
        put("-", (a, b) -> a - b);
        put("*", (a, b) -> a * b);
        put("/", (a, b) -> a / b);
    }};
    
    public int evalRPN(String[] tokens) {

        Stack<Integer> stack = new Stack<>();

        for (String token : tokens) {
            
            if (!OPERATIONS.containsKey(token)) {
                stack.push(Integer.valueOf(token));
                continue;
            }
            
            int number2 = stack.pop();
            int number1 = stack.pop();
            BiFunction<Integer, Integer, Integer> operation = OPERATIONS.get(token);
            int result = operation.apply(number1, number2);
            stack.push(result);
        }
        
        return stack.pop();
        
    }
}
