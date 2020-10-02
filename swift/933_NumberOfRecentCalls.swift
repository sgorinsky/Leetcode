class RecentCounter {
    var front: Int = 0
    var calls: [Int] = [Int]()
    var size: Int = 0

    func ping(_ t: Int) -> Int {
        while front < size && calls[front] < t - 3000 {
            front += 1
        }
        size += 1
        calls.append(t)
        return size - front
    }
}

/**
 * Your RecentCounter object will be instantiated and called as such:
 * let obj = RecentCounter()
 * let ret_1: Int = obj.ping(t)
 */
