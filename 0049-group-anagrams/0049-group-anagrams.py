class Solution(object):
    def groupAnagrams(self, strs):
        """
        :type strs: List[str]
        :rtype: List[List[str]]
        """
        mapf = {}
        for s in strs:
            s_s = ''.join(sorted(s))
            if s_s in mapf:
                mapf[s_s].append(s)
            else:
                mapf[s_s] = [s]
                
        return mapf.values()

        