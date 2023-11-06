from Queue import PriorityQueue
class SeatManager(object):

    def __init__(self, n):
        self.size = n
        self.next = 1
        self.seats = PriorityQueue()

    def reserve(self):
        if not self.seats.empty():
            return self.seats.get()
        self.next += 1
        return self.next-1
        

    def unreserve(self, seatNumber):
        self.seats.put(seatNumber, seatNumber)
        


# Your SeatManager object will be instantiated and called as such:
# obj = SeatManager(n)
# param_1 = obj.reserve()
# obj.unreserve(seatNumber)