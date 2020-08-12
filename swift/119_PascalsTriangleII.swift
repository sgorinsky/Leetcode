class Solution {
    func getRow(_ rowIndex: Int) -> [Int] {
        if rowIndex == 0 {
            return [1]
        }
        
        var v: [Int] = getRow(rowIndex-1)
        
        var n = v.count
        var startIdx = v.index(v.startIndex, offsetBy: 1)
        var endIdx = v.index(v.endIndex, offsetBy: -1)
        
        for i in 1..<n {
            v[startIdx] = i <= n/2 ? v[startIdx] + v[endIdx] : v[endIdx]
            startIdx = v.index(after: startIdx)
            endIdx = v.index(before: endIdx)
        }
        
        v.append(1)
        return v
    }
}
