class Solution {
    func maxOperations(_ nums: [Int], _ k: Int) -> Int {
        var numCounts = [Int:Int]()
        var count = 0
        for n in nums {
            let complement = k - n
            if let currentCount = numCounts[complement], currentCount > 0 {
                numCounts[complement]! -= 1
                count += 1
            } else {
                numCounts[n] = numCounts[n] == nil ? 1 : numCounts[n]! + 1
            }
        }
        return count
    }
}
