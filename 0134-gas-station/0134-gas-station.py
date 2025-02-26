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
        while checked < n:
            tank = gas[i] - cost[i]

            j = i + 1
            while tank >= 0:
                if j - n - 1 == i:
                    return i
                tank += gas[j % n] - cost[j % n]
                j += 1

            checked += abs(j-i)
            i = j % n

        return -1

        