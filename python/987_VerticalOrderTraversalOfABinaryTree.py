# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def verticalTraversal(self, root: TreeNode) -> List[List[int]]:
        if not root:
            return []
        
        node_list = []
        def bfs(node):
            queue = deque([(node, 0, 0)])
            while queue:
                node, col, row = queue.popleft()
                if node:
                    node_list.append((row, col, node.val))
                    queue.append((node.left, col+1, row-1))
                    queue.append((node.right, col+1, row+1))
        
        bfs(root)
        node_list.sort()
        
        prev_col, prev_row, curr, res = node_list[0][0], node_list[0][1], [], []
        for col, row, val in node_list:
            print(f'up top: {val}')
            if col != prev_col:
                res.append(curr)
                curr = [val]
            else:
                curr.append(val)
            prev_col, prev_row = col, row
        
        res.append(curr)
        return res
                    
