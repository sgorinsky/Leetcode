class Solution:
    def lengthOfLIS(self, nums: List[int]) -> int:
        mono = []
        for n in nums:
            if not mono or n > mono[-1]:
                mono.append(n)
            else:
                for i, m in enumerate(mono):
                    if n < m and (i == 0 or n > mono[i - 1]):
                        mono[i] = n
                        break
        return len(mono)
