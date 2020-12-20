class Solution {
    func maximumUniqueSubarray(_ nums: [Int]) -> Int {
        var counts = [Int](repeating: 0, count: 10001), lasts = [Int](repeating: 0, count: 10001)
        var l = 0, curr = 0, high = 0
        for (i, n) in nums.enumerated() {
            curr += n
            if counts[n] > 0 {
                if l <= lasts[n] {
                    for j in l...lasts[n] {
                        counts[nums[j]] = 0
                        curr -= nums[j]
                    }
                    l = lasts[n] + 1
                }
            }
            counts[n] = 1
            lasts[n] = i
            high = max(curr, high)
        }
        return high
    }
}
