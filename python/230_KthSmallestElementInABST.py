# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def kthSmallest(self, root: TreeNode, k: int) -> int:
        self.bst_array = []
        def populateArray(node):
            if not node:
                return
            
            if node.left:
                populateArray(node.left)
            
            self.bst_array.append(node.val)
            
            if node.right:
                populateArray(node.right)
                
        populateArray(root)
        return self.bst_array[k-1]
