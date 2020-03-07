# iterating for pop without built in python slicing
class MyQueue:
    def __init__(self):
        """
        Initialize your data structure here.
        """
        self.stack = []
        

    def push(self, x: int) -> None:
        """
        Push element x to the back of queue.
        """
        self.stack.append(x)
        

    def pop(self) -> int:
        """
        Removes the element from in front of queue and returns that element.
        """
        if self.stack:
            front, self.stack = self.stack[0], [self.stack[i] for i in range(1, len(self.stack))]
            return front
        return None
        

    def peek(self) -> int:
        """
        Get the front element.
        """
        return self.stack[0] if self.stack else None
        

    def empty(self) -> bool:
        """
        Returns whether the queue is empty.
        """
        return not self.stack
        


# Your MyQueue object will be instantiated and called as such:
# obj = MyQueue()
# obj.push(x)
# param_2 = obj.pop()
# param_3 = obj.peek()
# param_4 = obj.empty()

# quicker pythonic slicing for pop
class MyQueue:
    def __init__(self):
        """
        Initialize your data structure here.
        """
        self.stack = []
        

    def push(self, x: int) -> None:
        """
        Push element x to the back of queue.
        """
        self.stack.append(x)
        

    def pop(self) -> int:
        """
        Removes the element from in front of queue and returns that element.
        """
        if len(self.stack) > 0:
            popped = self.stack[0]
            self.stack = [] if len(self.stack) == 1 else self.stack[1:]
            return popped
        return None

    def peek(self) -> int:
        """
        Get the front element.
        """
        return self.stack[0] if self.stack else None

    def empty(self) -> bool:
        """
        Returns whether the queue is empty.
        """
        return not self.stack
