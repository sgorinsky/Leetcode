class Solution {
    func removeCoveredIntervals(_ intervals: [[Int]]) -> Int {
        var total = intervals.count
        var sortedIntervals = intervals.sorted(by: { (a,b) in 
            return a[0] == b[0] ? a[1] > b[1] : a[0] < b[0]
        })
        var coverCandidate = sortedIntervals[0]
        for i in 1..<sortedIntervals.count {
            if coverCandidate[0] <= sortedIntervals[i][0] && coverCandidate[1] >= sortedIntervals[i][1] {
                total -= 1
            } else {
                coverCandidate = sortedIntervals[i]
            }
        }
        return total
    }
}
