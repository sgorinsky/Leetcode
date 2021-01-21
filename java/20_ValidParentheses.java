class Solution {
    public boolean isValid(String s) {
        HashMap<Character, Character> closedParens = new HashMap<Character, Character>() {{
            put(')', '(');
            put(']', '[');
            put('}', '{');
        }};
        Stack<Character> stack = new Stack<Character>();
        for (Character c : s.toCharArray()) {
            if (closedParens.get(c) == null) {
                stack.push(c);
            } else {
                if (stack.isEmpty() || closedParens.get(c) != stack.peek()) {
                    return false;
                } else {
                    stack.pop();
                }
            }
        }
        return stack.isEmpty();
    }
}

class Solution {
    HashMap<Character, Character> closedParens = new HashMap<Character, Character>() {{
        put(')', '(');
        put(']', '[');
        put('}', '{');
    }};
    public boolean isValid(String s) {
        List<Character> stack = new ArrayList<Character>();
        int size = 0;
        for (Character c : s.toCharArray()) {
            if (stack.isEmpty() || closedParens.get(c) == null) {
                stack.add(c);
                size++;
            } else {
                if (closedParens.get(c) == stack.get(size-1)) {
                    stack.remove(--size);
                } else {
                    return false;
                }
            }
        }
        return stack.isEmpty();
    }
}
