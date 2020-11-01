class Solution {
    func canFormArray(_ arr: [Int], _ pieces: [[Int]]) -> Bool {
        var arrOrders = [Int : Int]()
        for (i, n) in arr.enumerated() {
            arrOrders[n] = i
        }
        
        for row in pieces {
            for i in 1..<row.count {
                if arrOrders[row[i]] == nil || (arrOrders[row[i]] ?? -1) - 1 != (arrOrders[row[i-1]] ?? -1) {
                    return false
                }
            }
        }
        return true
    }
}
