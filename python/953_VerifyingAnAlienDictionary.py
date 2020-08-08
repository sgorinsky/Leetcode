class Solution:
    def isAlienSorted(self, words: List[str], order: str) -> bool:
        order_dict = {}
        for i, l in enumerate(order):
            order_dict[l] = i
        
        def check(w1, w2):
            if not (w1 and w2):
                return len(w1) <= len(w2)
            elif order_dict[w1[0]] < order_dict[w2[0]]:
                return True
            elif order_dict[w1[0]] > order_dict[w2[0]]:
                return False
            else:
                return check(w1[1:], w2[1:])
        
        prev = words[0]
        for i in range(1, len(words)):
            if not check(prev, words[i]):
                return False
            prev = words[i]
        return True
