class Solution {
    func bitwiseComplement(_ N: Int) -> Int {
        if N == 0 { return 1 }
        var lengthOfBitmask: Int = Int(log(Double(N)) / log(2.0)) + 1
        var bitmask = (1 << lengthOfBitmask) - 1;
        return bitmask ^ N;
    }
}
