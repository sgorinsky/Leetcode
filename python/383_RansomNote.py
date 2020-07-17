class Solution:
    def canConstruct(self, ransomNote: str, magazine: str) -> bool:
        mag_counts = {}
        for l in magazine:
            mag_counts[l] = 1 if l not in mag_counts else mag_counts[l] + 1
            
        for l in ransomNote:
            if l not in mag_counts or mag_counts[l] == 0:
                return False
            else:
                mag_counts[l] -= 1
        return True
