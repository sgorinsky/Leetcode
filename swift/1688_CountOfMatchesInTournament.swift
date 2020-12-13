class Solution {
    func numberOfMatches(_ n: Int) -> Int {
        if n == 0 || n == 1 { return 0 }
        else if n == 2 { return 1 }
        var m = n / 2
        return m + numberOfMatches(n - m)
    }
}
