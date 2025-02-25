class RandomizedSet(object):

    def __init__(self):
        self.content = {}

    def insert(self, val):
        """
        :type val: int
        :rtype: bool
        """
        if val in self.content:
            return False

        self.content[val] = 1
        return True

    def remove(self, val):
        """
        :type val: int
        :rtype: bool
        """
        if val not in self.content:
            return False

        del self.content[val]
        return True

    def getRandom(self):
        """
        :rtype: int
        """
        return random.choice(self.content.keys())


# Your RandomizedSet object will be instantiated and called as such:
# obj = RandomizedSet()
# param_1 = obj.insert(val)
# param_2 = obj.remove(val)
# param_3 = obj.getRandom()