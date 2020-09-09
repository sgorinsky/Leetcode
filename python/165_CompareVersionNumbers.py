class Solution:
    def compareVersion(self, version1: str, version2: str) -> int:
        v1, v2 = version1.split('.'), version2.split('.')
        i, j = 0, 0
        while i < len(v1) and j < len(v2):
            n1, n2 = int(v1[i]), int(v2[j])
            if (n1 != n2):
                return -1 if n1 < n2 else 1
            i += 1
            j += 1
        
        if i < len(v1) or j < len(v2):
            while i < len(v1):
                if int(v1[i]) != 0:
                    return 1
                i += 1
            while j < len(v2):
                if int(v2[j]) != 0:
                    return -1
                j += 1
        
        return 0
            
