# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def isValidSequence(self, root: TreeNode, arr: List[int]) -> bool:
        if not root or not arr: 
            return False
        def helper(node, idx):
            if node and idx == len(arr)-1 and node.val == arr[idx]:
                return not (node.right or node.left)
            elif not node or idx >= len(arr):
                return False
            
            value = False
            if node.right and node.right.val == arr[idx+1]:
                if helper(node.right, idx+1): 
                    value = True
            if node.left and node.left.val == arr[idx+1]:
                if helper(node.left, idx+1): 
                    value = True
            
            return value
            
        return helper(root, 0)
        
