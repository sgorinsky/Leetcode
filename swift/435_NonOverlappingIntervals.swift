class Solution {
    func eraseOverlapIntervals(_ intervals: [[Int]]) -> Int {
        if intervals.count == 0 { return 0 }
        var sortedIntervals: [[Int]] = intervals // since intervals is let const
        sortedIntervals.sort(by: {
            $0[1] < $1[1]
        })
        
        var currIdx = sortedIntervals.index(sortedIntervals.startIndex, offsetBy: 0)
        var prev: [Int] = sortedIntervals[currIdx]
        var count = 0
        
        for _ in 1..<sortedIntervals.count {
            currIdx = sortedIntervals.index(after: currIdx)
            var curr: [Int] = sortedIntervals[currIdx]
            if prev[1] > curr[0] {
                if prev[1] > curr[1] {
                    prev = curr
                }
                count += 1
            } else {
                prev = curr
            }
        }
        return count
    }
}
