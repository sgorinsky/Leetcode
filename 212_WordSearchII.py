class Solution:
    def findWords(self, board: List[List[str]], words: List[str]) -> List[str]:
        if not board or not board[0]:
            return []
        
        settify_words, full_words = set(), set()
        for word in words:
            full_words.add(word)
            curr_word = ''
            for l in word:
                curr_word += l
                settify_words.add(curr_word)

                
        def helper(row, col, curr='', visited=set()):
            visited.add((row, col))
            res = []
            if curr in full_words:
                res += [curr]
            elif curr not in settify_words:
                return []         
            
            if len(board)-1 > row and curr + board[row+1][col] in settify_words and (row+1, col) not in visited:
                res += helper(row+1, col, curr+board[row+1][col], visited)
                visited.remove((row+1, col))
            if len(board[0])-1 > col and curr + board[row][col+1] in settify_words and (row, col+1) not in visited:
                res += helper(row, col+1, curr+board[row][col+1], visited)
                visited.remove((row, col+1))
            if row > 0 and curr + board[row-1][col] in settify_words and (row-1, col) not in visited:
                res += helper(row-1, col, curr+board[row-1][col], visited)
                visited.remove((row-1, col))
            if col > 0 and curr + board[row][col-1] in settify_words and (row, col-1) not in visited:
                res += helper(row, col-1, curr+board[row][col-1], visited)
                visited.remove((row, col-1))
            return res
            
        ans = []
        for i in range(len(board)):
            for j in range(len(board[0])):
                # visited=[[False for _ in range(len(board[0]))] for _ in range(len(board))]
                ans += helper(i, j, board[i][j], set())
                
        return set(ans)
