class Solution {
    func concatenatedBinary(_ n: Int) -> Int {
        var length = 0, result = 0, MOD = 1000000007
        for x in 1...n {
            if x & (x - 1) == 0 {
                length += 1 // length of binary representations of x increase each time x is a power of 2
            }
            result = (result << length | x) % MOD
        }
        return result
    }
}
