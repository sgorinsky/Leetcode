class Solution {
    func longestPalindrome(_ s: String) -> Int {
        var letterCounts: [Character : Int] = [Character : Int]()
        
        for l in s {
            letterCounts[l] = letterCounts[l] == nil ? 1 : letterCounts[l]! + 1
        }
        
        var ans: Int = 0
        for (k, v) in letterCounts {
            ans += v / 2 * 2
            if (ans % 2 == 0 && v % 2 == 1) {
                ans += 1
            }
        }
        return ans
    }
}
