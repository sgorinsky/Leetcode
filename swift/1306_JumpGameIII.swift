class Solution {
    func canReach(_ a: [Int], _ start: Int) -> Bool {
        var arr = a
        var stack = [start]
        var N = arr.count
        while !stack.isEmpty {
            var idx = stack.removeLast()
            if idx < 0 || idx >= N { continue }
            else if arr[idx] == 0 { return true }
            else if arr[idx] > 0 {
                stack.append(idx - arr[idx])
                stack.append(idx + arr[idx])
                arr[idx] = -arr[idx]
            }
        }
        return false
    }
}
