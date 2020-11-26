class Solution {
    func permute(_ nums: [Int]) -> [[Int]] {
        func helper(_ currentPermutation: [Int]) {
            if numsSet.isEmpty {
                permutations.append(currentPermutation)
                return;
            }
            
            var curr = currentPermutation
            for n in nums {
                if numsSet.contains(n) {
                    numsSet.remove(n)
                    curr.append(n)
                    
                    helper(curr)
                    
                    numsSet.insert(n)
                    curr.removeLast()
                }
            }
        }
        
        var permutations = [[Int]]()
        var numsSet = Set<Int>(nums)
        helper([Int]())
        return permutations
    }
}
