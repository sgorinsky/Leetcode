class Solution {
    func sortArrayByParityII(_ nums: [Int]) -> [Int] {
        var A = nums
        var j = 1
        for i in stride(from: 0, to: A.count, by: 2) {
            if A[i] % 2 == 1 {
                while A[j] % 2 == 1 {
                    j += 2
                }
                let temp = A[i]
                A[i] = A[j]
                A[j] = temp
            }
        }
        return A
    }
}
