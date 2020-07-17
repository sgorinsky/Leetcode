# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    all_values = {}
    current_highest_count = [0, []]
    def findFrequentTreeSum(self, tree: TreeNode) -> List[int]:
        self.all_values = {}
        self.current_highest_count = [0, []]
    
        def helper(root):
            if not root:
                return root
            current_sum = self.sumTree(root)
            self.all_values[current_sum] = 1 if current_sum not in self.all_values else self.all_values[current_sum]+1
            if self.all_values[current_sum] > self.current_highest_count[0]:
                self.current_highest_count = [self.all_values[current_sum], [current_sum]]
            elif self.all_values[current_sum] == self.current_highest_count[0]:
                self.current_highest_count = [self.all_values[current_sum], self.current_highest_count[1] + [current_sum]]

            if root.left:
                helper(root.left)
            if root.right:
                helper(root.right)
            return self.current_highest_count[1].copy()
        num_list = helper(tree)
        return num_list
        
    
    def sumTree(self, tree: TreeNode) -> int:
        def helper(root):
            if not root:
                return root
            total[0] += root.val
            if root.left:
                helper(root.left)
            if root.right:
                helper(root.right)
            return root
        total = [0]
        helper(tree)
        return total[0]

# Initial attempt at an O(N) approach with a postorder traversal
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    highest_count = [0, []]
    def findFrequentTreeSum(self, tree: TreeNode) -> List[int]:
        self.highest_count = [0, []]
        num_list = {}
        def helper(root, total):
            if not root:
                return root
            if root.left:
                total = helper(root.left, total)
            if root.right:
                total = helper(root.right, total)
            total += root.val
            print(f'root: {root.val}')
            print(f'total: {total}')
            num_list[total] = 1 if total not in num_list else num_list[total] + 1
            if num_list[total] > self.highest_count[0]:
                self.highest_count = [num_list[total], [num_list[total]]]
            elif num_list[total] == self.highest_count[0]:
                self.highest_count = [num_list[total], self.highest_count[1] + [total]]
            return total
        helper(tree, 0)
        return self.highest_count[1]
