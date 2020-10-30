class Solution {
    func maxDistToClosest(_ seats: [Int]) -> Int {
        var N = seats.count, high = 0
        // check from right 0s
        for i in 0..<N {
            if seats[i] == 1 {
                high = i
                break
            }
        }
        
        // check from right
        for i in 0..<N {
            if seats[N-i-1] == 1 {
                high = max(high, i)
                break
            }
        }
        
        // check middles
        var prev = 0
        for i in 0..<N {
            if seats[i] == 1 {
                high = max(high, (i - prev) / 2)
                prev = i
            }
        }
        return high
    }
}
