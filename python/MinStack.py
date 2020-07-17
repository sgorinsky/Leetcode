# As part of leetcode 30 day challenge day 10
class MinStack:

    def __init__(self):
        """
        initialize your data structure here.
        """
        self.stack = []
        

    def push(self, x: int) -> None:
        self.stack.append([x, x]) if not self.stack else self.stack.append([x, min(x, self.stack[-1][1])])

    def pop(self) -> None:
        if self.stack:
            del self.stack[-1]

    def top(self) -> int:
        if self.stack:
            return self.stack[-1][0]

    def getMin(self) -> int:
        return self.stack[-1][1]


# Your MinStack object will be instantiated and called as such:
# obj = MinStack()
# obj.push(x)
# obj.pop()
# param_3 = obj.top()
# param_4 = obj.getMin()
