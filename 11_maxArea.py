def maxArea(height: List[int]) -> int:
    i = 0
    j = len(height) -1
    highest = 0
    while i < j:
        shortest = height[i] if height[i] < height[j] else height[j]
        current_area = shortest * (j-i)
        if current_area > highest:
            highest = current_area
        if height[i] > height[j]:
            j -= 1
        else:
            i += 1
    return highest
