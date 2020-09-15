import kotlin.math.max
class Solution {
    fun rob(nums: IntArray): Int {
        var prev: Int = 0
        var curr: Int = 0
        
        for (n in nums) {
            val temp: Int = curr
            curr = max(prev + n, curr)
            prev = temp
        }
        return curr
    }
}
