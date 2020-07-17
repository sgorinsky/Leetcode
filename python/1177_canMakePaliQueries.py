def canMakePaliQueries(self, s: str, queries: List[List[int]]) -> List[bool]:
    palindrome_bool_array = []
    for begin, end, leeway in queries:
        missing: int = 0
        half: int = (end + 1 - begin) // 2
        letters: dict = {} 

        if (end+1-begin) % 2 == 1:
            letters[s[half]] = 1

        for i in range(half):
            equal = s[begin+i] == s[end-i]
            l1 = s[begin+i]
            l2 = s[end-i]
            if equal:
                if l1 in letters:
                    letters[l1] += 1
                else:
                    letters[l1] = 1
            else:
                if l1 in letters:
                    letters[l1] += 1
                else:
                    letters[l1] = 1
                if l2 in letters:
                    letters[l2] += 1
                else:
                    letters[l2] = 1
                missing += 1
        for k, v in letters.items():
            missing -= v//2
        palindrome_bool_array.append(leeway >= missing)
    return palindrome_bool_array

'''
test cases
"abcda"
[[3,3,0],[1,2,0],[0,3,1],[0,3,2],[0,4,1]]
"abcbc"
[[3,3,0],[1,2,0],[0,3,1],[0,3,2],[0,4,1]]
"abad"
[[3,3,0],[1,2,0],[0,3,1],[0,3,2],[0,3,1]]
"abcd"
[[3,3,0],[1,2,0],[0,3,1],[0,3,2],[0,3,1]]
"hunu"
[[3,3,0],[1,2,0],[0,3,1],[0,3,2],[0,3,1]]
"pazcds"
[[1,5,5],[4,5,1],[5,5,1],[2,5,2],[3,4,1],[0,3,0],[1,2,0],[2,5,0],[5,5,1],[0,3,1],[1,5,1],[2,5,0],[5,5,1],[0,1,0],[5,5,1],[4,5,1],[1,3,3]]
'''
