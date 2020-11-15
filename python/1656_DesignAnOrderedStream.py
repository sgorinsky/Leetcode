class OrderedStream:

    def __init__(self, n: int):
        self.stream = [""] * 1001
        self.head = 1

    def insert(self, idx: int, value: str) -> List[str]:
        self.stream[idx] = value
        res = []
        i = self.head
        while self.stream[i] != "":
            res.append(self.stream[i])
            i += 1
        self.head = i
        return res
