class MyQueue {
public:
    vector<int> stack;
    int head, back;
    /** Initialize your data structure here. */
    MyQueue() {
        head = 0, back = -1;
    }
    
    /** Push element x to the back of queue. */
    void push(int x) {
        stack.push_back(x);
        back++;
    }
    
    /** Removes the element from in front of queue and returns that element. */
    int pop() {
        return stack[head++];
    }
    
    /** Get the front element. */
    int peek() {
        return stack[head];
    }
    
    /** Returns whether the queue is empty. */
    bool empty() {
        return head > back;
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */
