class Solution:
    def computeArea(self, A: int, B: int, C: int, D: int, E: int, F: int, G: int, H: int) -> int:
        # inner height
        if F <= B < H:
            if D > H:
                height = H - B
            else:
                height = D - B
        elif B < F < D:
            if H > D:
                height = D - F
            else:
                height = H - F
        else:
            height = 0
                

        # inner width
        if E <= A < G:
            if C > G:
                width = G - A
            else:
                width = C - A
        elif A < E < C:
            if G > C:
                width = C - E
            else:
                width = G - E
        else:
            width = 0

        rect_A = (D-B) * (C-A)
        rect_B = (H-F) * (G-E)
        inner = height * width
        
        return rect_A + rect_B - inner

# smaller solution
class Solution:
    def computeArea(self, A: int, B: int, C: int, D: int, E: int, F: int, G: int, H: int) -> int:
        height, width = min(H, D) - max(B, F), min(G, C) - max(E, A)
        innerArea = height * width if height > 0 and width > 0 else 0
        return (D-B)*(C-A) + (H-F)*(G-E) - innerArea
