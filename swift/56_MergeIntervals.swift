class Solution {
    func merge(_ intervals: [[Int]]) -> [[Int]] {
        if intervals.isEmpty { return [[Int]]() }
        let sortedIntervals = intervals.sorted { a, b in 
            return a[0] == b[0] ? a[1] > b[1] : a[0] < b[0]
        }
        
        var currentInterval = sortedIntervals[0]
        var mergedIntervals = [[Int]]()
        for i in 1..<sortedIntervals.count {
            if currentInterval[1] >= sortedIntervals[i][0] {
                currentInterval[1] = max(sortedIntervals[i][1], currentInterval[1])
            } else {
                mergedIntervals.append(currentInterval)
                currentInterval = sortedIntervals[i]
            }
        }
        mergedIntervals.append(currentInterval)
        return mergedIntervals
    }
}
