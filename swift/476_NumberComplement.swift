class Solution {
    func findComplement(_ N: Int) -> Int {
        var lengthOfBitmask: Int = Int(log(Double(N)) / log(2.0)) + 1
        var bitmask = (1 << lengthOfBitmask) - 1;
        return N ^ bitmask;
    }
}
