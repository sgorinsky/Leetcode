class MinStack {
public:
    vector<pair<int, int>> stack;
    int smallest;
    /** initialize your data structure here. */
    MinStack() {
        stack = {};
        smallest = INT_MAX;
    }
    
    void push(int x) {
        smallest = min(smallest, x);
        stack.push_back({x, smallest});
    }
    
    void pop() {
        stack.pop_back();
        smallest = stack.empty() ? INT_MAX : stack.back().second;
    }
    
    int top() {
        return stack.back().first;
    }
    
    int getMin() {
        return stack.back().second;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(x);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
