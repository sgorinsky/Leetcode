class MyStack:
    
    def __init__(self):
        """
        Initialize your data structure here.
        """
        self.q1 = deque()
        self.q2 = deque()
        

    def push(self, x: int) -> None:
        """
        Push element x onto stack.
        """
        while self.q2: self.q1.appendleft(self.q2.pop())
        self.q2.appendleft(x)
        while self.q1: self.q2.appendleft(self.q1.pop())

    def pop(self) -> int:
        """
        Removes the element on top of the stack and returns that element.
        """
        return self.q2.pop()

    def top(self) -> int:
        """
        Get the top element.
        """
        return self.q2[-1]

    def empty(self) -> bool:
        """
        Returns whether the stack is empty.
        """
        return not self.q2


# Your MyStack object will be instantiated and called as such:
# obj = MyStack()
# obj.push(x)
# param_2 = obj.pop()
# param_3 = obj.top()
# param_4 = obj.empty()

class MyStack:

    def __init__(self):
        """
        Initialize your data structure here.
        """
        self.stack = []

    def push(self, x: int) -> None:
        """
        Push element x onto stack.
        """
        self.stack = self.stack + [x]

    def pop(self) -> int:
        """
        Removes the element on top of the stack and returns that element.
        """
        last = self.stack[-1]
        self.stack = self.stack[:len(self.stack)-1]
        
        return last

    def top(self) -> int:
        """
        Get the top element.
        """
        return self.stack[-1]
        

    def empty(self) -> bool:
        """
        Returns whether the stack is empty.
        """
        for _ in self.stack: return False
        return True


# Your MyStack object will be instantiated and called as such:
# obj = MyStack()
# obj.push(x)
# param_2 = obj.pop()
# param_3 = obj.top()
# param_4 = obj.empty()
