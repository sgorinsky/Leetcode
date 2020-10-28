
class MyQueue {
    var layoverStack = [Int](), mainStack = [Int]()
    /** Push element x to the back of queue. */
    func push(_ x: Int) {
        while !mainStack.isEmpty { layoverStack.append(mainStack.removeLast()) }
        layoverStack.append(x)
        while !layoverStack.isEmpty { mainStack.append(layoverStack.removeLast()) }
    }
    
    /** Removes the element from in front of queue and returns that element. */
    func pop() -> Int {
        return mainStack.removeLast()
    }
    
    /** Get the front element. */
    func peek() -> Int {
        return mainStack.last!
    }
    
    /** Returns whether the queue is empty. */
    func empty() -> Bool {
        return mainStack.isEmpty
    }
}

/**
 * Your MyQueue object will be instantiated and called as such:
 * let obj = MyQueue()
 * obj.push(x)
 * let ret_2: Int = obj.pop()
 * let ret_3: Int = obj.peek()
 * let ret_4: Bool = obj.empty()
 */
