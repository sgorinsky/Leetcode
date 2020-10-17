class MyCircularQueue {
    var q: [Int]
    var end: Int
    var head = -1, tail = -1
    /** Initialize your data structure here. Set the size of the queue to be k. */
    init(_ k: Int) {
        q = [Int](repeating: 0, count: k)
        end = k
    }
    
    /** Insert an element into the circular queue. Return true if the operation is successful. */
    func enQueue(_ value: Int) -> Bool {
        if isFull() { return false }
        else if head == -1 { head = 0 }
        
        tail = (tail + 1) % end
        q[tail] = value
        return true
    }
    
    /** Delete an element from the circular queue. Return true if the operation is successful. */
    func deQueue() -> Bool {
        if isEmpty() { 
            return false
        } else if head == tail { 
            head = -1
            tail = -1
        } else {
            head = (head + 1) % end
        }
        return true
    }
    
    /** Get the front item from the queue. */
    func Front() -> Int {
        if isEmpty() { return -1 }
        return q[head]
    }
    
    /** Get the last item from the queue. */
    func Rear() -> Int {
        if isEmpty() { return -1 }
        return q[tail]
    }
    
    /** Checks whether the circular queue is empty or not. */
    func isEmpty() -> Bool {
        return end == 0 || head == -1
    }
    
    /** Checks whether the circular queue is full or not. */
    func isFull() -> Bool {
        return end == 0 || (tail + 1) % end == head
    }
}

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * let obj = MyCircularQueue(k)
 * let ret_1: Bool = obj.enQueue(value)
 * let ret_2: Bool = obj.deQueue()
 * let ret_3: Int = obj.Front()
 * let ret_4: Int = obj.Rear()
 * let ret_5: Bool = obj.isEmpty()
 * let ret_6: Bool = obj.isFull()
 */
