class StockSpanner:

    def __init__(self):
        self.last = False
        self.span = 1
        self.jumps = []
        self.last_stop = -1

    def next(self, price: int) -> int:
        if not self.last:
            self.last = price
            self.jumps.append([price, self.last_stop, self.span])
            return self.span
        
        if price >= self.last:
            self.span += 1
        else:
            self.span = 1
            self.last_stop = len(self.jumps)-1
        
        self.last = price
        self.jumps.append([price, self.last_stop, self.span])
        
        i = len(self.jumps)-1
        total = 0
        while i >= 0 and self.jumps[i][0] <= price:
            total += self.jumps[i][2]
            i = self.jumps[i][1]
        
        return total
        


# Your StockSpanner object will be instantiated and called as such:
# obj = StockSpanner()
# param_1 = obj.next(price)
