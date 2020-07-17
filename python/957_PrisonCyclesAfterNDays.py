class Solution:
    def prisonAfterNDays(self, cells: List[int], N: int) -> List[int]:
        cycles = []
        for _ in range(7):
            zeroes, ones = [0,7], []
            for i in range(1, 7):
                if cells[i-1] == cells[i+1]:
                    ones.append(i)
                else:
                    zeroes.append(i)
            
            for entry in zeroes:
                cells[entry] = 0
            for entry in ones:
                cells[entry] = 1
            
            cycles.append([entry for entry in cells])
            
        return cycles[(N-1)%7] if (N-1)//7 % 2 == 0 or N <= 7 else cycles[(N-1)%7][::-1]
