def lengthOfLongestSubstring(s: str) -> int:

    start = high = count = 0
    letters = {}

    for index, i in enumerate(s):
        if i in letters and letters[i] >= start:
            high = max(high, count)
            count = index - letters[i]
            start = letters[i]+1
        else:
            count += 1
        letters[i] = index
    return max(high, count)
