class Solution:
    def simplifyPath(self, path: str) -> str:
        if not path: return ''
        dirs, stack = path.split('/'), []
        for d in dirs:
            if stack and list(d) == ['.','.']: stack.pop()
            elif d and list(d) != ['.'] and list(d) != ['.','.']: stack.append(d)
        return '/' + '/'.join(stack)
