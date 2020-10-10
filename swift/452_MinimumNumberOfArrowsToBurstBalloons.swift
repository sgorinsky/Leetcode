class Solution {
    func findMinArrowShots(_ points: [[Int]]) -> Int {
        var balloons = points.sorted(by: { 
            (a,b) in
            return a[0] < b[0]
        })
        var balloonCount = 0, start = -12345, end = -12345 // random start and end 
        for balloon in balloons {
            if balloon[0] >= start && balloon[0] <= end {
                end = min(end, balloon[1])
            } else {
                balloonCount += 1
                start = balloon[0]
                end = balloon[1]
            }
        }
        return balloonCount
    }
}
