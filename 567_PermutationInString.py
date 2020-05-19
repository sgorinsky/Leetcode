class Solution:
    def checkInclusion(self, s1: str, s2: str) -> bool:
        if len(s1) > len(s2):
            return False
        
        char_list_s1 = [0 for i in range(26)]
        for l in s1:
            char_list_s1[ord(l)-97] += 1
        
        m = len(s1)
        n = len(s2)
        
        curr_char_list = [0 for i in range(26)]
        for l in s2[:m]:
            curr_char_list[ord(l)-97] += 1
        
        for i in range(m, n):
            if curr_char_list == char_list_s1:
                return True
            
            # sliding window
            curr_char_list[ord(s2[i-m])-97] -= 1
            curr_char_list[ord(s2[i])-97] += 1
        
        return curr_char_list == char_list_s1 # covers cases where n == m or permutation occurs s[n-m:]
