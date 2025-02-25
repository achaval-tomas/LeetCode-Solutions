class Solution(object):
    def hIndex(self, citations):
        """
        :type citations: List[int]
        :rtype: int
        """
        counts = [0 for _ in range(1001)]
        for p in citations:
            counts[p] += 1

        total_papers = 0
        for i in range(1000, -1, -1):
            total_papers += counts[i]
            if total_papers >= i:
                return i
        
        return 0
        