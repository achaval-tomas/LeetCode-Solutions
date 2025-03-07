class Solution(object):
    def isValid(self, s):
        """
        :type s: str
        :rtype: bool
        """
        pairs = {
            '(': ')',
            '{': '}',
            '[': ']'
        }
        stack = []
        for c in s:
            if c in pairs:
                stack.append(c)
            elif stack:
                if c != pairs[stack[len(stack) - 1]]:
                    return False
                else:
                    del stack[len(stack) - 1]
            else:
                return False
        
        return not stack
