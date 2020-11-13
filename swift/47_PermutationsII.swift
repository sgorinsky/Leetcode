class Solution {
    func permuteUnique(_ allNumbers: [Int]) -> [[Int]] {
        func getPermutations(_ candidate: [Int]) -> [[Int]] {
            var candidatePermutation = candidate
            if candidatePermutation.count == nums.count {
                allPermutations.append(candidatePermutation)
                return allPermutations
            }
            
            for i in 0..<nums.count {
                if nums[i] != -11 && (i == 0 || nums[i] != nums[i-1]) {
                    var temp = nums[i]
                    nums[i] = -11
                    candidatePermutation.append(temp)
                    getPermutations(candidatePermutation)
                    candidatePermutation.removeLast()
                    nums[i] = temp
                }
            }
            
            return allPermutations
        }
        var nums = allNumbers.sorted()
        var allPermutations = [[Int]]()
        return getPermutations([Int]())
    }
}
