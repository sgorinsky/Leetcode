class Solution {
    func merge(_ nums1: inout [Int], _ m: Int, _ nums2: [Int], _ n: Int) {
        var i = m - 1, j = n - 1
        for (idx, n) in nums1.enumerated().reversed() {
            if i >= 0 && j >= 0 {
                if nums1[i] > nums2[j] {
                    nums1[idx] = nums1[i]
                    i -= 1
                } else {
                    nums1[idx] = nums2[j]
                    j -= 1
                }
            } else {
                if i >= 0 {
                    nums1[idx] = nums1[i]
                    i -= 1
                } else {
                    nums1[idx] = nums2[j]
                    j -= 1
                }
            }
        }
    }
}
