class Solution:
    def allPathsSourceTarget(self, graph: List[List[int]]) -> List[List[int]]:
        res = []
        def dfs(idx, curr):
            for node in graph[idx]:
                dfs(node, curr+[node])
            
            if idx == len(graph)-1:
                res.append(curr)
        
        dfs(0, [0])
            
        return res
