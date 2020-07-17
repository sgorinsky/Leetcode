class FirstUnique:

    def __init__(self, nums: List[int]):
        self.numCounts = {}
        for n in nums:
            self.numCounts[n] = 1 if n not in self.numCounts else self.numCounts[n] + 1
        self.uniqueNums = [n for n in nums if self.numCounts[n] == 1]
                
            
    def showFirstUnique(self) -> int:
        return self.uniqueNums[0] if self.uniqueNums else -1

    def add(self, value: int) -> None:
        if value not in self.numCounts:
            self.numCounts[value] = 1
            self.uniqueNums.append(value)
        else:
            self.numCounts[value] += 1
        
        while 0 < len(self.uniqueNums) and self.numCounts[self.uniqueNums[0]] > 1:
            del self.uniqueNums[0]
            


# Your FirstUnique object will be instantiated and called as such:
# obj = FirstUnique(nums)
# param_1 = obj.showFirstUnique()
# obj.add(value)
