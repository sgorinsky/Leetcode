# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

# O(N) recursive solution that evalutates left and right child candidacy of entry by comparing val to parent and grandparent
class Solution:
    def bstFromPreorder(self, preorder: List[int]) -> TreeNode:
        if not preorder: return None
        
        self.idx = 0
        def helper(idx, limit):
            if idx == len(preorder) or preorder[idx] > limit:
                return None
            
            root = TreeNode(preorder[idx])
            self.idx += 1

            root.left = helper(self.idx, root.val)
            root.right = helper(self.idx, limit)

            return root
        
        return helper(self.idx, float('inf'))

class Solution:
    def bstFromPreorder(self, preorder: List[int]) -> TreeNode:
        if not preorder: return None
        root = TreeNode(preorder[0])

        for i in range(1, len(preorder)):
            self.appendNode(root, preorder[i])
        
        return root
    
    
    def appendNode(self, root, val):
        curr = root
        while curr:
            if val > curr.val:
                if curr.right:
                    curr = curr.right
                else:
                    curr.right = TreeNode(val)
                    break
            else:
                if curr.left:
                    curr = curr.left
                else:
                    curr.left = TreeNode(val)
                    break
        return root
