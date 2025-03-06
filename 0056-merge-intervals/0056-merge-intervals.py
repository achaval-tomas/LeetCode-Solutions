class Solution(object):
    def merge(self, intervals):
        """
        :type intervals: List[List[int]]
        :rtype: List[List[int]]
        """
        intervals.sort()
        print(intervals)
        n = len(intervals)
        ans = []
        i = 0
        while i < n:
            start = intervals[i][0]
            end = intervals[i][1]
            i += 1
            while i < n and intervals[i][0] <= end:
                end = max(intervals[i][1], end)
                i += 1
            ans.append([start, end])

        return ans