class MyCircularQueue {
public:
    vector<int> q;
    int head, tail, end;
    /** Initialize your data structure here. Set the size of the queue to be k. */
    MyCircularQueue(int k) {
        q.resize(k, 0);
        head = -1, tail = -1;
        end = k;
    }
    
    /** Insert an element into the circular queue. Return true if the operation is successful. */
    bool enQueue(int value) {
        if (isFull()) return false;
        
        if (head == -1) head = 0;
        tail = (tail + 1) % end;
        q[tail] = value;
        return true;
    }
    
    /** Delete an element from the circular queue. Return true if the operation is successful. */
    bool deQueue() {
        if (isEmpty()) return false;
        else if (head == tail) head = -1, tail = -1;
        else head = (head + 1) % end;
        
        return true;
    }
    
    /** Get the front item from the queue. */
    int Front() {
        if (!isEmpty()) return q[head];
        return -1;
    }
    
    /** Get the last item from the queue. */
    int Rear() {
        if (!isEmpty()) return q[tail];
        return -1;
    }
    
    /** Checks whether the circular queue is empty or not. */
    bool isEmpty() {
        return end == 0 || head == -1;
    }
    
    /** Checks whether the circular queue is full or not. */
    bool isFull() {
        return end == 0 || (head + end - 1) % end == tail;
    }
};

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue* obj = new MyCircularQueue(k);
 * bool param_1 = obj->enQueue(value);
 * bool param_2 = obj->deQueue();
 * int param_3 = obj->Front();
 * int param_4 = obj->Rear();
 * bool param_5 = obj->isEmpty();
 * bool param_6 = obj->isFull();
 */
