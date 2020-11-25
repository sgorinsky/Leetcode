class Solution {
    func smallestRepunitDivByK(_ K: Int) -> Int {
        if K % 2 == 0 || K % 5 == 0 { return -1 }
        
        var n = 1
        var length = 1
        while length < 10000000 {
            if n % K == 0 || n == 0 { return length }
            length += 1
            n = (n * 10 + 1) % K
        }
        return -1
    }
}
