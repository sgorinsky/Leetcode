class Solution {
    func pseudoPalindromicPaths (_ root: TreeNode?) -> Int {
        func sumPseudoPalindromePaths(_ node: TreeNode?, _ length: Int) -> Int {
            if node == nil {
                return 0
            }
            
            var sum = 0
            numCountsInPath[node!.val - 1] += 1
            if node?.left == nil && node?.right == nil {
                sum = isPseudoPalindrome(length + 1)
            } else {
                sum = sumPseudoPalindromePaths(node?.left, length + 1) + sumPseudoPalindromePaths(node?.right, length + 1)
            }
            
            numCountsInPath[node!.val - 1] -= 1
            return sum
        }
        
        func isPseudoPalindrome(_ length: Int) -> Int {
            var count = length % 2
            for n in numCountsInPath {
                if n % 2 == 1 {
                    count -= 1
                    if count < 0 {
                        return 0
                    }
                }
            }
            return 1
        }
        
        var numCountsInPath = [Int](repeating: 0, count: 9)
        return sumPseudoPalindromePaths(root, 0)
    }
}
