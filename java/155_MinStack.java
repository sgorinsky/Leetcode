class MinStack {
    List<int[]> stack;
    int smallest;
    int sz;
    /** initialize your data structure here. */
    public MinStack() {
        sz = 0;
        stack = new ArrayList<int[]>();
        smallest = Integer.MAX_VALUE;
    }
    
    public void push(int x) {
        smallest = Math.min(x, smallest);
        stack.add(new int[]{x, smallest});
        sz++;
    }
    
    public void pop() {
        stack.remove(--sz);
        smallest = stack.isEmpty() ? Integer.MAX_VALUE : stack.get(sz - 1)[1];
    }
    
    public int top() {
        return stack.get(sz - 1)[0];
    }
    
    public int getMin() {
        return smallest;
    }
}

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack obj = new MinStack();
 * obj.push(x);
 * obj.pop();
 * int param_3 = obj.top();
 * int param_4 = obj.getMin();
 */
