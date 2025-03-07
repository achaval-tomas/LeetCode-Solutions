class Solution(object):
    def evalRPN(self, tokens):
        """
        :type tokens: List[str]
        :rtype: int
        """
        stack = []
        i = 0
        n = len(tokens)
        operators = {
            "+": lambda a, b: a + b,
            "-": lambda a, b: a - b,
            "*": lambda a, b: a * b,
            "/": lambda a, b: int(float(a) / b), # truncate towards zero
        }
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
            print(stack)

        return int(stack[0])