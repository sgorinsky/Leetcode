
class CombinationIterator {
    var combinations: [String]
    init(_ characters: String, _ combinationLength: Int) {
        let n: Int = characters.count
        let k: Int = combinationLength
        combinations = [String]()
        
        for bitmask in 0..<(1 << n) {
            if countBits(bitmask) == k {
                var curr: String = ""
                var jIdx = characters.index(characters.startIndex, offsetBy: 0)
                for j in 0..<n {
                    if (bitmask & (1 << (n - j - 1))) != 0 {
                        curr.append("\(characters[jIdx])")
                    }
                    jIdx = characters.index(after: jIdx)
                }
                combinations.append(curr)
            }
        }
    }
    
    func next() -> String {
        return combinations.popLast()!
    }
    
    func hasNext() -> Bool {
        return !combinations.isEmpty
    }
    
    func countBits(_ num: Int) -> Int {
        var count: Int = 0
        var currNum: Int = num
        while currNum > 0 {
            currNum &= currNum-1
            count += 1
        }
        return count
    }
}

/**
 * Your CombinationIterator object will be instantiated and called as such:
 * let obj = CombinationIterator(characters, combinationLength)
 * let ret_1: String = obj.next()
 * let ret_2: Bool = obj.hasNext()
 */
