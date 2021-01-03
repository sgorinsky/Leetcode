class Solution {
    func countPairs(_ deliciousness: [Int]) -> Int {
        var high = 1000000007
        var deliciousnessCounts = [Int:Int]()
        var counts = 0
        for n in deliciousness {
            for i in 0..<22 {
                counts = (counts + (deliciousnessCounts[(1 << i) - n] ?? 0)) % high
            }
            deliciousnessCounts[n] = (deliciousnessCounts[n] ?? 0) + 1
        }
        return counts
    }
}
