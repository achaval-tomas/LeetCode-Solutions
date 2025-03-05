class Solution(object):
    def canConstruct(self, ransomNote, magazine):
        """
        :type ransomNote: str
        :type magazine: str
        :rtype: bool
        """
        multiset = {}
        for c in ransomNote:
            multiset.setdefault(c, 0)
            multiset[c] += 1
        
        for c in magazine:
            if c in multiset:
                multiset[c] -= 1
        
        return all(c <= 0 for c in multiset.values())
        