class Solution {
    func openLock(_ deadends: [String], _ target: String) -> Int {
        let deadSet = Set(deadends.map { $0 })
        var visitedSet = Set<String>()
        var q: [(String, Int)] = [("0000", 0)]
        var head = 0, size = 1

        while head < q.count || size > 9998 {
            let (currString, rotationCount) = q[head]
            head += 1

            if currString == target {
                return rotationCount
            } else if !deadSet.contains(currString) {
                for (idx, letter) in zip(currString.indices, currString) {
                    for d in stride(from: -1, through: 1, by: 2) {
                        let changedChar = (Int(String(letter))! + d + 10) % 10
                        let nextIdx = currString.index(after: idx)
                        let queueableString = "\(currString[..<idx])\(changedChar)\(currString[nextIdx..<currString.endIndex])"

                        if !visitedSet.contains(queueableString) {
                            visitedSet.insert(queueableString)
                            q.append((queueableString, rotationCount + 1))
                            size += 1
                        }
                    }
                }
            }
        }
        return -1
    }
}
