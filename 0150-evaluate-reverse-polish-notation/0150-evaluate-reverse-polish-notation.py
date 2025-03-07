class Solution(object):
    def evalRPN(self, tokens):
        """
        :type tokens: List[str]
        :rtype: int
        """
        n = len(tokens)
        if n == 1:
            return int(tokens[0])

        operators = {
            "+": lambda a, b: a + b,
            "-": lambda a, b: a - b,
            "*": lambda a, b: a * b,
            "/": lambda a, b: int(float(a) / b), # truncate towards zero
        }
        stack = []
        i = 0
        while i < n:
            num_count = 0
            while tokens[i] not in operators:
                stack.append(int(tokens[i]))
                i += 1
            b = stack.pop(-1)
            a = stack.pop(-1)
            res = operators[tokens[i]](a, b)
            stack.append(res)
            i += 1

        return int(stack[0])