class MyCalendar(object):

    def __init__(self):
        self.cal = [[int, int]]

    def book(self, start, end):
        for i in self.cal:
            if end>i[0] and start<i[1]:
                return False
        self.cal.append([start, end])
        return True
        


# Your MyCalendar object will be instantiated and called as such:
# obj = MyCalendar()
# param_1 = obj.book(start,end)