# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    total = 0
    all_values = {}
    current_highest_count = [0, []]
    
    def findFrequentTreeSum(self, root: TreeNode) -> List[int]:
        if not root:
            return root
        current_sum = self.sumTree(root)
        self.all_values[current_sum] = 1 if current_sum not in self.all_values else self.all_values[current_sum]+1
        if self.all_values[current_sum] > self.current_highest_count[0]:
            self.current_highest_count = [self.all_values[current_sum], [current_sum]]
        elif self.all_values[current_sum] == self.current_highest_count[0]:
            self.current_highest_count = [self.all_values[current_sum], self.current_highest_count[1] + [current_sum]]
        
        if root.left:
            self.findFrequentTreeSum(root.left)
        if root.right:
            self.findFrequentTreeSum(root.right)
        return self.current_highest_count[1]
        
    
    def sumTree(self, tree: TreeNode) -> int:
        self.total = 0
        def helper(root):
            if not root:
                return root
            self.total += root.val
            if root.left:
                helper(root.left)
            if root.right:
                helper(root.right)
            return root
        helper(tree)
        return self.total
