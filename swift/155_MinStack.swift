class MinStack {
    var stack = [[Int]]()
    var smallest = Int.max
    
    func push(_ x: Int) {
        smallest = min(smallest, x)
        stack.append([x, smallest])
    }
    
    func pop() {
        stack.removeLast()[1]
        smallest = stack.isEmpty ? Int.max : stack.last![1]
    }
    
    func top() -> Int {
        return stack.last![0]
    }
    
    func getMin() -> Int {
        return smallest
    }
}

/**
 * Your MinStack object will be instantiated and called as such:
 * let obj = MinStack()
 * obj.push(x)
 * obj.pop()
 * let ret_3: Int = obj.top()
 * let ret_4: Int = obj.getMin()
 */
