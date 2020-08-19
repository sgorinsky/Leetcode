class Solution {
    func replaceElements(_ array: [Int]) -> [Int] {
        var arr = array
        var idx = arr.index(arr.endIndex, offsetBy: -1)
        var high = -1
        
        // populate dictionary
        for _ in 0..<arr.count {
            var temp = arr[idx]
            arr[idx] = high
            if temp > high {
                high = temp
            }
            idx = arr.index(before: idx)
        }
        return arr
    }
}
