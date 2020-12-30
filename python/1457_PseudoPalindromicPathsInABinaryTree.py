class Solution:
    def pseudoPalindromicPaths (self, root: TreeNode) -> int:
        counts = [0 for _ in range(9)]
        def helper(node, length):
            if not node:
                return 0
            
            total = 0
            counts[node.val - 1] += 1
            length += 1
            if not node.right and not node.left:
                total = pseudo(length)
            else:
                total = helper(node.left, length) + helper(node.right, length)
            length -= 1
            counts[node.val - 1] -= 1
            
            return total
        
        def pseudo(length):
            length %= 2
            for n in counts:
                if n % 2:
                    length -= 1
                    if length < 0:
                        return 0
            return 1
        
        return helper(root, 0)
