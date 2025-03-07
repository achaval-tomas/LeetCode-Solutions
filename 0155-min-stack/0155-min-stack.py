class MinStack(object):

    def __init__(self):
        # values are pairs (value, min) where min is the minimum
        # at the moment value was added
        self.values = []
        

    def push(self, val):
        """
        :type val: int
        :rtype: None
        """
        newMin = min(val, self.values[-1][1]) if self.values else val
        self.values.append((val, newMin))

    def pop(self):
        """
        :rtype: None
        """
        if self.values:
            self.values.pop(-1)

        if self.values:
            self.min = self.values[-1][1]

    def top(self):
        """
        :rtype: int
        """
        return self.values[-1][0] if self.values else None

    def getMin(self):
        """
        :rtype: int
        """
        return self.values[-1][1] if self.values else None
        


# Your MinStack object will be instantiated and called as such:
# obj = MinStack()
# obj.push(val)
# obj.pop()
# param_3 = obj.top()
# param_4 = obj.getMin()