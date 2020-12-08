class Solution {
    func numPairsDivisibleBy60(_ time: [Int]) -> Int {
        var moddedTimes = [Int](repeating: 0, count: 60)
        var count = 0
        
        for t in time { moddedTimes[t % 60] += 1 }
        for t in 0...30 {
            if t == 0 || t == 30 {
                if moddedTimes[t] < 2 { continue }
                for x in 1..<moddedTimes[t] {
                    count += x
                }
            } else {
                count += (moddedTimes[t] * moddedTimes[60 - t])
            }
        }
        return count
    }
}
