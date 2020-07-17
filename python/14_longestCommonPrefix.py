def longestCommonPrefix(self, strs: List[str]) -> str:
    prefix = ""
    not_done = True
    letter = 0

    while not_done:
        if len(strs)>0 and len(strs[0]) >= letter+1:
            current = strs[0][letter]
            for i in strs:
                if len(i) <= letter or current != i[letter]:
                    not_done = False
                    break
            if not_done:
                prefix += current
            letter += 1
        else:
            not_done = False
            break
    return prefix
