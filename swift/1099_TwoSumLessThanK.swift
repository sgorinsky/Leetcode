class Solution {
    func twoSumLessThanK(_ A: [Int], _ K: Int) -> Int {
        var sortedNums = A.sorted { $0 < $1 }
        var closestSum = -1
        
        var left = 0, right = sortedNums.count - 1
        while left < right {
            var candidateSum = sortedNums[left] + sortedNums[right]
            if candidateSum > K {
                right -= 1
            } else {
                if candidateSum < K { closestSum = max(candidateSum, closestSum) }
                left += 1
            }
        }
        return closestSum
    }
}
