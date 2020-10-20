class Solution {
    func minDominoRotations(_ A: [Int], _ B: [Int]) -> Int {
        func checkRotations(_ target: Int) -> Int {
            var upperRotations = 0, lowerRotations = 0
            for i in 0..<A.count {
                if A[i] != target && B[i] != target { return -1 }
                else if A[i] != target { upperRotations += 1 }
                else if B[i] != target { lowerRotations += 1 }
            }
            return min(upperRotations, lowerRotations)
        }
        var rotations = checkRotations(A[0])
        return rotations != -1 || A[0] == B[0] ? rotations : checkRotations(B[0])
    }
}
