class Solution {
    func reachNumber(_ target: Int) -> Int {
        var t = abs(target)
        var k = 0
        while t > 0 {
            k += 1
            t -= k
        }
        return t % 2 == 0 ? k : k + 1 + k % 2
    }
}
