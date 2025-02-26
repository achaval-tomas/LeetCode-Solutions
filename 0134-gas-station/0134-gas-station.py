class Solution(object):
    def canCompleteCircuit(self, gas, cost):
        """
        :type gas: List[int]
        :type cost: List[int]
        :rtype: int
        """
        n = len(gas)
        i = 0
        checked = 0
        while True:
            if checked >= n:
                return -1

            tank = gas[i] - cost[i]
            if tank < 0:
                checked += 1
                i = (i+1) % n
                continue

            j = i
            while tank >= 0:
                if j - n == i:
                    return i
                j += 1
                tank += gas[j % n] - cost[j % n]

            checked += abs(j-i)
            i = (j + 1) % n

        return -1

        