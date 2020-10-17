class Vector2D {
    var vectorOfNums: [Int]
    var head: Int
    init(_ v: [[Int]]) {
        vectorOfNums = [Int]()
        head = 0
        for nums in v {
            for num in nums {
                vectorOfNums.append(num)
            }
        }
    }
    
    func next() -> Int {
        var temp = vectorOfNums[head]
        head += 1
        return temp
    }
    
    func hasNext() -> Bool {
        return head < vectorOfNums.count
    }
}

/**
 * Your Vector2D object will be instantiated and called as such:
 * let obj = Vector2D(v)
 * let ret_1: Int = obj.next()
 * let ret_2: Bool = obj.hasNext()
 */
