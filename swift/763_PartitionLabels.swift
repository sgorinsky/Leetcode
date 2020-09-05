class Solution {
    func partitionLabels(_ s: String) -> [Int] {
        var idx = s.startIndex
        var N = 0
        var lastIndices: Dictionary<Character, Int> = [Character: Int]()
        while idx != s.endIndex {
            lastIndices[s[idx]] = N
            N += 1
            s.formIndex(after: &idx)
        }
        
        idx = s.startIndex
        
        var partitions: [Int] = [Int]()
        var curr: Int = 0
        var last: Int = 0
        for i in 0..<N {
            let lastIdx = lastIndices[s[idx]] as! Int
            curr = lastIdx > curr ? lastIdx : curr
            if (i == curr) {
                partitions.append(curr - last + 1)
                last = curr + 1
            }
            s.formIndex(after: &idx)
        }
        return partitions
        
    }
}
