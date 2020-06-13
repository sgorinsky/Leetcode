import random
class RandomizedSet:

    def __init__(self):
        """
        Initialize your data structure here.
        """
        self.random_set = set()
        self.count = 0

    def insert(self, val: int) -> bool:
        """
        Inserts a value to the set. Returns true if the set did not already contain the specified element.
        """
        if val not in self.random_set:
            self.random_set.add(val)
            return True
        return False

    def remove(self, val: int) -> bool:
        """
        Removes a value from the set. Returns true if the set contained the specified element.
        """
        if val in self.random_set:
            self.random_set.remove(val)
            return True
        return False

    def getRandom(self) -> int:
        """
        Get a random element from the set.
        """
        return random.sample(self.random_set, 1)[0]
        
        


# Your RandomizedSet object will be instantiated and called as such:
# obj = RandomizedSet()
# param_1 = obj.insert(val)
# param_2 = obj.remove(val)
# param_3 = obj.getRandom()

import random
class RandomizedSet:

    def __init__(self):
        """
        Initialize your data structure here.
        """
        self.random_set = set()
        self.count = 0

    def insert(self, val: int) -> bool:
        """
        Inserts a value to the set. Returns true if the set did not already contain the specified element.
        """
        if val not in self.random_set:
            self.count += 1
            self.random_set.add(val)
            return True
        return False

    def remove(self, val: int) -> bool:
        """
        Removes a value from the set. Returns true if the set contained the specified element.
        """
        if val in self.random_set:
            self.count -= 1
            self.random_set.remove(val)
            return True
        return False

    def getRandom(self) -> int:
        """
        Get a random element from the set.
        """
        if self.random_set == set():
            return None
        e = iter(self.random_set)
        a = next(e)
        
        rand = random.randint(0, self.count-1)
        for i in range(rand):
            a = next(e)
        return a
        
        


# Your RandomizedSet object will be instantiated and called as such:
# obj = RandomizedSet()
# param_1 = obj.insert(val)
# param_2 = obj.remove(val)
# param_3 = obj.getRandom()
