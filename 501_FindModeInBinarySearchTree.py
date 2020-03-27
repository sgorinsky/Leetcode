# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def findMode(self, root: TreeNode) -> List[int]:
        self.num_counts = {}
        self.high = {'nums': [], 'count': 0}
        def helper(tree):
            if not tree:
                return self.high['nums']
            
            self.num_counts[tree.val] = 1 if tree.val not in self.num_counts else self.num_counts[tree.val]+1
            if self.num_counts[tree.val] > self.high['count']:
                self.high['nums'], self.high['count'] = {tree.val}, self.num_counts[tree.val]
            elif self.num_counts[tree.val] == self.high['count']:
                if tree.val not in self.high['nums']:
                    self.high['nums'].add(tree.val)
                
            if tree.left:
                helper(tree.left)
            if tree.right:
                helper(tree.right)
            
            return self.high['nums']
        high_nums = list(helper(root))
        return high_nums
