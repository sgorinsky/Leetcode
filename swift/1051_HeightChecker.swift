class Solution {
    func heightChecker(_ heights: [Int]) -> Int {
        var sortedHeights: [Int] = heights.sorted(by: {
            a, b in
            return a < b
        })
        var count: Int = 0, N: Int = heights.count
        var idx = heights.index(heights.startIndex, offsetBy: 0) // refers to sortedHeights idx as well
        
        for _ in 0..<N {
            if sortedHeights[idx] != heights[idx] { count += 1 }
            sortedHeights.formIndex(after: &idx)
        }
        return count
    }
}
