class Solution:
    def kthLargestValue(self, matrix: List[List[int]], k: int) -> int:
        pq = []
        for i, row in enumerate(matrix):
            for j, n in enumerate(row):
                above, left = 0 if i == 0 else matrix[i - 1][j], 0 if j == 0 else matrix[i][j - 1]
                matrix[i][j] ^= above ^ left
                pq.append(matrix[i][j])
                if i < len(matrix) - 1 and j < len(matrix[0]) - 1:
                    matrix[i + 1][j + 1] ^= matrix[i][j]
        
        pq.sort(reverse = True)
        return pq[k - 1]
