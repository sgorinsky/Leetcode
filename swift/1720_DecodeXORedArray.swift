class Solution {
    func decode(_ encoded: [Int], _ first: Int) -> [Int] {
        var decoded = [first]
        for n in encoded {
            decoded.append(n ^ decoded.last!)
        }
        return decoded
    }
}
