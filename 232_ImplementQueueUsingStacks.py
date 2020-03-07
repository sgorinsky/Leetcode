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
