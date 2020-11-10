class Solution:
    def flipAndInvertImage(self, A: List[List[int]]) -> List[List[int]]:
        return [[n ^ 1 for n in row[::-1]] for row in A]
