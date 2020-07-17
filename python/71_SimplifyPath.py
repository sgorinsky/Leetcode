class Solution:
    def simplifyPath(self, path: str) -> str:
        if not path: return ''
        dirs, stack = path.split('/'), []
        for d in dirs:
            if stack and list(d) == ['.','.']: stack.pop()
            elif d and list(d) != ['.'] and list(d) != ['.','.']: stack.append(d)
        return '/' + '/'.join(stack)

# one pass for split
class Solution:
    def simplifyPath(self, path: str) -> str:
        i, stack = 0, []
        
        while i < len(path):
            word = ''
            if path[i] == '/': i += 1
            while i < len(path) and path[i] != '/':
                word += path[i]
                i += 1
            if word == '..':
                if stack: stack.pop()
            elif word == '.':
                continue
            elif word:
                stack.append(word)
            i += 1
        
        return '/' + '/'.join(stack)
