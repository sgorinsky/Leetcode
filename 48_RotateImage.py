class Solution:
    def rotate(self, matrix: List[List[int]]) -> None:
        """
        Do not return anything, modify matrix in-place instead.
        """
        if not matrix:
            return matrix
        if type(matrix[0]) == list:
            i = 0
            while i < len(matrix[0]):
                matrix.append([matrix[-i-1-j][i] for j in range(len(matrix[0]))])
                i += 1
            del matrix[:len(matrix[0])]
