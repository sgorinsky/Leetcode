class Solution:
    def findOrder(self, numCourses: int, prerequisites: List[List[int]]) -> List[int]:
        if not prerequisites and numCourses:
            return [i for i in range(numCourses-1, -1, -1)]
        elif not prerequisites:
            return []
        
        high = 0
        for x, y in prerequisites:
            high = max(x, y, high)
        adjacencies = [[] for i in range(high+1)]
        
        # create adjacency list
        for edge in prerequisites:
            adjacencies[edge[1]].append(edge[0])
        
        V, ordering = [0 for _ in range(len(adjacencies))], [0 for _ in range(len(adjacencies))]
        curr_idx, visited = len(adjacencies)-1 , []
        
        def dfs(idx=curr_idx):
            V[idx] = 1
            for nodeId in adjacencies[idx]:
                if V[nodeId] == 0:
                    dfs(nodeId)
                if V[nodeId] == 1:
                    self.cycle = True
                    return
                
            V[idx] = 2
            visited.append(idx)
        
        self.cycle = False
        for i in range(len(adjacencies)):
            if V[i] == 0:
                dfs(i)
                for nodeId in visited:
                    ordering[curr_idx] = nodeId
                    curr_idx -= 1
                visited = []
            elif self.cycle:
                return []
                    
        return ordering[:numCourses] if numCourses <= len(ordering) else [numCourses-i-1 for i in range(numCourses-len(ordering))] + ordering
        
        
        
        
        
            
            
        
        
        
