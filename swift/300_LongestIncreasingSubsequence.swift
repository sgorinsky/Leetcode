class Solution {
    func lengthOfLIS(_ nums: [Int]) -> Int {
        var monotonicIncreasingList = [Int]()
        for n in nums {
            if monotonicIncreasingList.isEmpty || n > monotonicIncreasingList.last! {
                monotonicIncreasingList.append(n)
            } else {
                for i in 0..<monotonicIncreasingList.count {
                    if n < monotonicIncreasingList[i] && (i == 0 || n > monotonicIncreasingList[i - 1]) {
                        monotonicIncreasingList[i] = n
                        break
                    }
                }
            }
        }
        return monotonicIncreasingList.count
    }
}
