class Solution:

    def floodFill(self, image: List[List[int]], sr: int, sc: int, newColor: int) -> List[List[int]]:
        if not (0 <= sr < len(image) and 0 <= sr < len(image[0]) and image):
            return image

        self.color = image[sr][sc]
        self.visited = {}

        def changeCardinals(row, col):
            if image[row][col] != self.color:
                return
            
            self.visited[(row, col)] = True
            if image[row][col] == self.color: 
                image[row][col] = newColor
            
            if row-1 >= 0 and (row-1, col) not in self.visited:
                changeCardinals(row-1, col)
            if col-1 >= 0 and (row, col-1) not in self.visited:
                changeCardinals(row, col-1)
            if row+1 < len(image) and (row+1, col) not in self.visited:
                changeCardinals(row+1, col)
            if col+1 < len(image[0]) and (row, col+1) not in self.visited:
                changeCardinals(row, col+1)

        changeCardinals(sr, sc)
        return image
