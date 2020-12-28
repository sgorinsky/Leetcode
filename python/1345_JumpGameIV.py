class Solution:
    def minJumps(self, arr: List[int]) -> int:
        N = len(arr)
        if N <= 1: return 0
        
        graph = {}
        for i, n in enumerate(arr):
            if n in graph:
                graph[n].append(i)
            else:
                graph[n] = [i]
        
        visited = [False for _ in range(N)]
        layers = [0]
        count = 0
        
        while layers:
            nxt = []
            
            for node in layers:
                if node == N - 1:
                    return count
            
                for child in graph[arr[node]]:
                    if not visited[child]:
                        nxt.append(child)
                        visited[child] = True
                
                for child in [node - 1, node + 1]:
                    if 0 <= child < N and not visited[child]:
                        nxt.append(child)
                        visited[child] = True
                
                graph[arr[node]] = []
                        
            count += 1
            layers = nxt
        
        return -1
        
        
        
