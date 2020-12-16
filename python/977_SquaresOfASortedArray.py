class Solution:
    def sortedSquares(self, nums: List[int]) -> List[int]:
        start, end, i = 0, len(nums) - 1, len(nums) - 1
        res = [0 for _ in range(len(nums))]
        while start <= end:
            if abs(nums[start]) > abs(nums[end]):
                res[i] = nums[start] * nums[start]
                start += 1
            else:
                res[i] = nums[end] * nums[end]
                end -= 1
            i -= 1
        return res

class Solution:
    def sortedSquares(self, A: List[int]) -> List[int]:
        idx, neg_squares = 0, []
        while idx < len(A) and A[idx] < 0:
            neg_squares.append(A[idx]**2)
            idx += 1

        squares = [n**2 for n in A[idx:]]
        
        i = 0
        while i < len(squares):
            if neg_squares and squares[i] >= neg_squares[-1]:
                squares.insert(i, neg_squares[-1])
                del neg_squares[-1]
            i += 1
        
        if not squares:
            return neg_squares[::-1]
        elif neg_squares and neg_squares[-1] > squares[-1]: 
            while neg_squares:
                squares.append(neg_squares[-1])
                del neg_squares[-1]
        
        return squares
        
        
        
