class Solution {
    func minPartitions(_ n: String) -> Int {
        var high = 1
        for d in n {
            high = max(Int(String(d))!, high)
        }
        return high
    }
}
