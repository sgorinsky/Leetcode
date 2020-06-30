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

                
        def helper(row, col, curr='', visited=[]):
            visited[row][col] = True
            if curr in full_words:
                return [curr]
            elif curr not in settify_words:
                return []
            
            res = []
            if len(board)-1 > row and curr + board[row+1][col] in settify_words and not visited[row+1][col]:
                res += helper(row+1, col, curr+board[row+1][col], visited)
            if len(board[0])-1 > col and curr + board[row][col+1] in settify_words and not visited[row][col+1]:
                res += helper(row, col+1, curr+board[row][col+1], visited)
            if row > 0 and curr + board[row-1][col] in settify_words and not visited[row-1][col]:
                res += helper(row-1, col, curr+board[row-1][col], visited)
            if col > 0 and curr + board[row][col-1] in settify_words and not visited[row][col-1]:
                res += helper(row, col-1, curr+board[row][col-1], visited)
            return res
            
        ans = []
        for i in range(len(board)):
            for j in range(len(board[0])):
                visited=[[False for _ in range(len(board[0]))] for _ in range(len(board))]
                ans += helper(i, j, board[i][j], visited)
                
        return set(ans)
