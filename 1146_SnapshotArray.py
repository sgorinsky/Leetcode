class SnapshotArray:

    def __init__(self, length: int):
        self.data = {}
        self.ver = 0
        self.data[self.ver] = {}

    def set(self, index: int, val: int) -> None:
        self.data[self.ver][index] = val

    def snap(self) -> int:
        self.ver += 1
        self.data[self.ver] = self.data[self.ver - 1].copy()
        return self.ver - 1
        
    def get(self, index: int, snap_id: int) -> int:
        return self.data[snap_id].get(index, 0) # Python get method, not recursive call


# Your SnapshotArray object will be instantiated and called as such:
# obj = SnapshotArray(length)
# obj.set(index,val)
# param_2 = obj.snap()
# param_3 = obj.get(index,snap_id)
