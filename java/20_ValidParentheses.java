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
