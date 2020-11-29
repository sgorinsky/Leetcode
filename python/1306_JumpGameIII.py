class Solution:
    def canReach(self, arr: List[int], start: int) -> bool:
        n = len(arr)
        q = deque([start])
        
        while q:
            idx = q.popleft()
            if idx < 0 or idx >= n: continue
            elif arr[idx] == 0: return True
            elif arr[idx] > 0:
                q.append(idx - arr[idx])
                q.append(idx + arr[idx])
                arr[idx] = -arr[idx]
        
        return False
