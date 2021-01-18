class Solution {
    func maxOperations(_ nums: [Int], _ k: Int) -> Int {
        var sortedNums = nums.sorted()
        var left = 0, right = sortedNums.count - 1
        var count = 0
        while left < right {
            var total = sortedNums[left] + sortedNums[right]
            if total == k {
                left += 1
                right -= 1
                count += 1
            } else if total > k {
                right -= 1
            } else {
                left += 1
            }
        }
        return count
    }
}

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
