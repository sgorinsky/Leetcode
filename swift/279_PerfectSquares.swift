class Solution {
    func numSquares(_ n: Int) -> Int {
        var squares = [Int]()
        var i = 0
        while i*i <= n {
            squares.append(i * i)
            if i*i == n { return 1 }
            i += 1
        }
        
        var count = n, head = squares.count - 1
        while head > 0 {
            for i in stride(from: head, to: 0, by: -1) {
                var currentCandidate = squares[head], checkingBackwardsHead = i, currentCount = 1
                while checkingBackwardsHead > 0 && currentCandidate < n && currentCount < count {
                    if currentCandidate + squares[checkingBackwardsHead] == n {
                        count = min(count, currentCount + 1)
                        break
                    } else if currentCandidate + squares[checkingBackwardsHead] > n {
                        checkingBackwardsHead -= 1
                    } else {
                        currentCount += 1
                        currentCandidate += squares[checkingBackwardsHead]
                    }
                }
            }
            head -= 1
        }
        return count
    }
}
