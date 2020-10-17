
class MovingAverage {
    var q: [Double]
    var capacity: Int
    var isFull = false
    var head = 0
    var total: Double = 0
    /** Initialize your data structure here. */
    init(_ size: Int) {
        capacity = size
        q = [Double](repeating: 0, count: size)
    }
    
    func next(_ val: Int) -> Double {
        if !isFull && head == capacity-1 {
            isFull = true
        } else if isFull {
            total -= q[head]
        }
        q[head] = Double(val)
        head = (head + 1) % capacity
        total += Double(val)
        return isFull ? total / Double(capacity) : total / Double(head)
    }
}

/**
 * Your MovingAverage object will be instantiated and called as such:
 * let obj = MovingAverage(size)
 * let ret_1: Double = obj.next(val)
 */
