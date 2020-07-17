# my implementation with doubly linked-list
class ListNode:
    def __init__(self, val):
        self.val = val
        self.previous = None
        self.next = None
    
class LRUCache:

    def __init__(self, capacity: int):
        self.capacity = capacity
        self.count = 0
        self.q = {'head': None, 'tail': None}
        self.cache = {}

    def get(self, key: int) -> int:
        if key in self.cache:
            curr = self.getCurrAndFixHead(key)
        return -1 if key not in self.cache else self.cache[key]

    def put(self, key: int, value: int) -> None:
        # detach node so we can put it at head
        curr = self.getCurrAndFixHead(key)
        
        if key not in self.cache:
            self.count += 1

        # pop tail
        if self.count > self.capacity:
            tail = self.q['tail']
            if tail and tail.next:
                self.q['tail'], tail.next.previous = tail.next, None
            else:
                curr.previous = tail
            
            self.q.pop(tail.val, None)
            self.cache.pop(tail.val, None)
            self.count -= 1
        
        self.cache[key] = value
            
    def getCurrAndFixHead(self, key):
        if key not in self.q:
            curr = ListNode(key)
            self.q[key] = curr
            if not self.q['tail']:
                self.q['tail'] = curr
        else:
            curr = self.q[key]
                
            # curr is in middle of queue, have before and after reference each other
            if curr.previous and curr.next:
                curr.previous.next, curr.next.previous = curr.next, curr.previous
            elif curr.next:
                self.q['tail'], self.q['tail'].previous = curr.next, None
                
        
        head = self.q['head']
        if head:
            head.next = curr
            if curr != head:
                curr.previous = head
        
        self.q['head'], curr.next = curr, None
        
        return curr

# Your LRUCache object will be instantiated and called as such:
# obj = LRUCache(capacity)
# param_1 = obj.get(key)
# obj.put(key,value)

class LRUCache:
    def __init__(self, capacity: int):
        self.capacity = capacity
        self.cache = OrderedDict()

    def get(self, key: int) -> int:
        if key in self.cache:
			# if we touch a key to return its value, we need to add it 
			# to the end of the least recently used items in our cache
            self.cache.move_to_end(key)
            return self.cache[key]
        return -1

    def put(self, key: int, value: int) -> None:
        # check if key already exists - if yes, move item to end and update the value
        if key in self.cache:
            self.cache.move_to_end(key)
        # if cache is full, remove least recent item (first value in OrderedDict)
        elif len(self.cache) == self.capacity:
            self.cache.popitem(last=False)
		# update/add value
        self.cache[key] = value
