class MinStack(object):

    def __init__(self):
        # values are pairs (value, min) where min is the minimum
        # at the moment value was added
        self.size = 0
        self.values = []
        self.min = 0
        

    def push(self, val):
        """
        :type val: int
        :rtype: None
        """
        newMin = min(val, self.min) if self.size else val
        self.min = newMin
        self.values.append((val, newMin))
        self.size += 1

    def pop(self):
        """
        :rtype: None
        """
        if self.size > 0:
            self.values.pop(-1)
            self.size -= 1
        if self.size:
            self.min = self.values[self.size - 1][1]

    def top(self):
        """
        :rtype: int
        """
        return self.values[self.size - 1][0] if self.size else None

    def getMin(self):
        """
        :rtype: int
        """
        return self.min if self.size else None
        


# Your MinStack object will be instantiated and called as such:
# obj = MinStack()
# obj.push(val)
# obj.pop()
# param_3 = obj.top()
# param_4 = obj.getMin()