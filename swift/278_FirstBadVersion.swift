class Solution : VersionControl {
    func firstBadVersion(_ n: Int) -> Int {
        var left = 0, right = n
        while left < right {
            var mid = left + (right - left) / 2
            var bad = isBadVersion(mid)
            if bad {
                right = mid
            } else {
                left = mid + 1
            }
        }
        return left
    }
}
