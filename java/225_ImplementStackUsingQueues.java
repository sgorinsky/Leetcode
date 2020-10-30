class MyStack {
    Queue<Integer> q1, q2;
    /** Initialize your data structure here. */
    public MyStack() {
        q1 = new LinkedList<Integer>();
        q2 = new LinkedList<Integer>();
    }
    
    /** Push element x onto stack. */
    public void push(int x) {
        while (!q2.isEmpty()) q1.add(q2.remove());
        q2.add(x);
        while (!q1.isEmpty()) q2.add(q1.remove());
    }
    
    /** Removes the element on top of the stack and returns that element. */
    public int pop() {
        return q2.remove();
    }
    
    /** Get the top element. */
    public int top() {
        return q2.peek();
    }
    
    /** Returns whether the stack is empty. */
    public boolean empty() {
        return q2.isEmpty();
    }
}

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack obj = new MyStack();
 * obj.push(x);
 * int param_2 = obj.pop();
 * int param_3 = obj.top();
 * boolean param_4 = obj.empty();
 */
