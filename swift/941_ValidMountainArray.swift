class Solution {
    func validMountainArray(_ arr: [Int]) -> Bool {
        if arr.count < 3 || arr[0] > arr[1] { return false }
        var isIncreasing = true
        for i in 0..<arr.count-1 {
            if arr[i] == arr[i + 1] { return false }
            if isIncreasing {
                if arr[i] > arr[i + 1] {
                    isIncreasing = false
                }
            } else {
                if arr[i] < arr[i + 1] {
                    return false
                }
            }
        }
        return !isIncreasing
    }
}
